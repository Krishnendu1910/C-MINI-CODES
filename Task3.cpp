#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define a structure for a task
struct Task {
    string description;
    bool isCompleted;

    Task(const string& desc) : description(desc), isCompleted(false) {}
};

// Function to display all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available in your to-do list.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "X" : " ") << "] "
             << tasks[i].description << endl;
    }
    cout << endl;
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    cout << "Enter the task description: ";
    cin.ignore();  // Clear the input buffer before reading a line
    string description;
    getline(cin, description);  // Read the task description as a full line

    tasks.emplace_back(description);  // Add the new task
    cout << "Task added successfully!\n\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to mark as completed.\n";
        return;
    }

    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number. Please try again.\n\n";
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to remove.\n";
        return;
    }

    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number. Please try again.\n\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!\n\n";
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\n--- To-Do List Manager ---\n";
    cout << "1. View Tasks\n";
    cout << "2. Add Task\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "--------------------------\n";
}

int main() {
    vector<Task> tasks;  // To store tasks
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n\n";
        }
    }

    return 0;
}
