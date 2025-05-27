#include <iostream>
#include <vector>

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

int main() {
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
         std::cout << "i = " << i << std::endl;
    }

    return 0;
    }