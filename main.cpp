#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;

struct Task {
    int id;
    string description;
    string status; // todo, in-progress, done
    string createdAt;
    string updatedAt;
};

vector<Task> tasks;
const string FILE_NAME = "tasks.json";

string getCurrentTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string str(dt);
    str.pop_back(); // remove newline
    return str;
}

void loadTasks() {
    ifstream file(FILE_NAME);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Task t;
        getline(ss, line, '|'); t.id = stoi(line);
        getline(ss, t.description, '|');
        getline(ss, t.status, '|');
        getline(ss, t.createdAt, '|');
        getline(ss, t.updatedAt, '|');
        tasks.push_back(t);
    }
    file.close();
}

void saveTasks() {
    ofstream file(FILE_NAME);
    for (auto& t : tasks) {
        file << t.id << "|" << t.description << "|" << t.status << "|"
             << t.createdAt << "|" << t.updatedAt << endl;
    }
    file.close();
}

int getNextId() {
    int maxId = 0;
    for (auto& t : tasks) {
        if (t.id > maxId) maxId = t.id;
    }
    return maxId + 1;
}

void addTask(const string& desc) {
    Task t;
    t.id = getNextId();
    t.description = desc;
    t.status = "todo";
    t.createdAt = getCurrentTimestamp();
    t.updatedAt = t.createdAt;
    tasks.push_back(t);
    saveTasks();
    cout << "Task added successfully (ID: " << t.id << ")\n";
}

void listTasks(string filter = "") {
    for (auto& t : tasks) {
        if (filter.empty() || t.status == filter) {
            cout << "[" << t.id << "] " << t.description << " (" << t.status << ")\n";
        }
    }
}

void updateTask(int id, const string& desc) {
    for (auto& t : tasks) {
        if (t.id == id) {
            t.description = desc;
            t.updatedAt = getCurrentTimestamp();
            saveTasks();
            cout << "Task updated.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void markStatus(int id, const string& newStatus) {
    for (auto& t : tasks) {
        if (t.id == id) {
            t.status = newStatus;
            t.updatedAt = getCurrentTimestamp();
            saveTasks();
            cout << "Task marked as " << newStatus << ".\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void deleteTask(int id) {
    auto it = remove_if(tasks.begin(), tasks.end(), [id](Task& t) { return t.id == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveTasks();
        cout << "Task deleted.\n";
    } else {
        cout << "Task not found.\n";
    }
}

int main(int argc, char* argv[]) {
    loadTasks();
    if (argc < 2) {
        cout << "Usage: task-cli <command> [args]\n";
        return 1;
    }

    string command = argv[1];
    if (command == "add" && argc >= 3) {
        addTask(argv[2]);
    } else {
        cout << "Unknown command or wrong arguments.\n";
    }
    return 0;
}