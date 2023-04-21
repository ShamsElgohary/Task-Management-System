#include <iostream>
#include <vector>
#include "TaskManagementSystem.hpp"

using namespace std;

int main()
{
    vector<Task> tasks;
    int option;

    while (true) {
        cout << "Task management system" << endl;
        cout << "----------------------" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Remove task" << endl;
        cout << "3. Display tasks" << endl;
        cout << "4. Mark task as completed" << endl;
        cout << "5. Filter tasks by priority" << endl;
        cout << "6. Set task priority" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << "Exiting..." << endl;
                return 0;

            case 1:
                {
                    string description;
                    int priority;
                    cout << "Enter task description: ";
                    cin.ignore();
                    getline(cin, description);
                    cout << "Enter task priority (1 = high, 2 = medium, 3 = low): ";
                    cin >> priority;
                    Task task(description, priority);
                    tasks.push_back(task);
                    cout << "Task added." << endl;
                }
                break;

            case 2:
                {
                    int index;
                    cout << "Enter task index to remove: ";
                    cin >> index;
                    if (index >= 0 && index < tasks.size()) {
                        tasks.erase(tasks.begin() + index);
                        cout << "Task removed." << endl;
                    }
                    else {
                        cout << "Invalid task index." << endl;
                    }
                }
                break;

            case 3:
                displayTasks(tasks);
                break;

            case 4:
                {
                    int index;
                    cout << "Enter task index to mark as completed: ";
                    cin >> index;
                    if (index >= 0 && index < tasks.size()) {
                        tasks[index].setCompleted(true);
                        cout << "Task marked as completed." << endl;
                    }
                    else {
                        cout << "Invalid task index." << endl;
                    }
                }
                break;

            case 5:
                filterTasksByPriority(tasks);
                break;

            case 6:
                setTaskPriority(tasks);
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }

        cout << endl;
    }
}