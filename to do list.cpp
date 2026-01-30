#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed;
};


class TodoList {
private:
    vector<Task> tasks;

public:
    
    void addTask(const string& desc) {
        Task newTask;
        newTask.description = desc;
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "Task added successfully.\n";
    }

   
    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        cout << "\n--- To-Do List ---\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". "
                 << tasks[i].description
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

   
    void markCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    }

    
    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    }
};


int main() {
    TodoList todo;
    int choice;
    string taskDescription;

    do {
        cout << "\n==== TO-DO LIST MANAGER ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;

            case 2:
                todo.viewTasks();
                break;

            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todo.markCompleted(taskNumber);
                break;
            }

            case 4: {
                int taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todo.removeTask(taskNumber);
                break;
            }

            case 5:
                cout << "Exiting application. Goodbye.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
