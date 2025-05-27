## 🧾 Task Tracker CLI (C++)

A simple command-line task management application built in C++ with file-based storage.  
Add, update, delete, and mark tasks as done or in progress — all from your terminal.

---

## Features

- Add tasks with descriptions  
- Update or delete tasks by ID  
- Mark tasks as `todo`, `in-progress`, or `done`  
- List all tasks or filter by status  
- Store tasks in a local file (simulated JSON using `|` as delimiter)  
- No external libraries used — fully native C++

---

## How to Use

### 📌 Add a new task
task-cli add "Buy groceries"

### ✏️ Update a task
task-cli update 1 "Buy groceries and cook dinner"

### ❌ Delete a task
task-cli delete 1

### 🚧 Mark as in progress / ✅ Mark as done
task-cli mark-in-progress 2
task-cli mark-done 2

### 📋 List tasks
task-cli list
task-cli list done
task-cli list todo
task-cli list in-progress

---

## Task Structure

Each task contains:

{
"id": 1,
"description": "Sample task",
"status": "todo",
"createdAt": "2025-05-27 12:00",
"updatedAt": "2025-05-27 12:00"
}

---

## Compile & Run

g++ task_tracker_cli.cpp -o task-cli
./task-cli add "Test the program"

---

## File Format

Tasks are stored line-by-line in a file named `tasks.json` using `|` as delimiter.

Example:
1|Buy groceries|todo|2025-05-27 12:00|2025-05-27 12:00

---

https://roadmap.sh/projects/task-tracker

---
