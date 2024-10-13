#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a new task
    void addTask(string description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // View all tasks
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " [";
                if (tasks[i].completed) {
                    cout << "Completed";
                } else {
                    cout << "Not completed";
                }
                cout << "]" << endl;
            }
        }
    }

    // Mark a task as completed
    void markCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task " << taskNumber << " marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Delete a task
    void deleteTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            cout << "Task deleted: " << tasks[taskNumber - 1].description << endl;
            tasks.erase(tasks.begin() + (taskNumber - 1));
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore(); // To consume the newline character left by cin
                string description;
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                cout << "Enter task number to mark as completed: ";
                int taskNumber;
                cin >> taskNumber;
                toDoList.markCompleted(taskNumber);
                break;
            }
            case 4: {
                cout << "Enter task number to delete: ";
                int taskNumber;
                cin >> taskNumber;
                toDoList.deleteTask(taskNumber);
                break;
            }
            case 5:
                cout << "Exiting To-Do List..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}