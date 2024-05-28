#include <iostream>
#include <string>

using namespace std;

class todo_list {
    string tasks[100]; // fixed size array for tasks
    int taskCount;
    string name;

public:
    todo_list() : taskCount(0) {}

    void setName(const string& userName) {
        name = userName;
    }

    string getName() const {
        return name;
    }

    void addTask(const string& task) {
        if (taskCount < 100) {
            tasks[taskCount++] = task;

            cout << "TASK ADDED SUCCESSFULLY "<<endl<<endl;
        } else {
            cout << "No more space available for adding tasks" << endl;
        }
    }

    void viewTasks() const {
        cout << "Name: " << name << endl;
        if (taskCount == 0) {
            cout << "No Tasks Added Yet" << endl;
            return;
        }
        for (int i = 0; i < taskCount; i++) {
            cout << "Task - " << i + 1 << ": " << tasks[i] << endl;
        }
    }

    void removeTask(const string& taskToRemove) {
        int taskIndex = -1;
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i] == taskToRemove) {
                taskIndex = i;
                break;
            }
        }

        if (taskIndex == -1) {
            cout << "Task not found." << endl;
            return;
        }

        for (int i = taskIndex; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        taskCount--;

        cout << "TASK REMOVED SUCCESSFULLY"<<endl;
    }
};

int main() {
    todo_list myTodoList;
    string userName;
    
    cout << "Enter your name: ";
    getline(cin, userName);
    myTodoList.setName(userName);

    int choice;
    do {
        cout << "********TO DO LIST********" << endl;
        cout << "1-Add Task" << endl;
        cout << "2-View Tasks" << endl;
        cout << "3-Remove Task" << endl;
        cout << "4-Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                getline(cin, task);
                myTodoList.addTask(task);
                break;
            }
            case 2:
                myTodoList.viewTasks();
                break;
            case 3: {
                string taskToRemove;
                cout << "Enter the task to remove: ";
                getline(cin, taskToRemove);
                myTodoList.removeTask(taskToRemove);
                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
