#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
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

int main() {
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
         std::cout << "i = " << i << std::endl;
    }

    return 0;
}