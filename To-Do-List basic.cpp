#include <iostream>
#include <windows.h>

using namespace std;

void print_tasks(string tasks[], int task_count)
    {
        cout << "Tasks to do: "<< endl;
        cout << "----------------------"<< endl;
        for (int i=0;i<task_count;i++)
        {
            cout << "Task"<<i+1<<" : "<<tasks[i]<<endl;
        }
        cout << "----------------------"<< endl;
    }

void remaining_tasks(string tasks[], int task_count)
    {
        cout << "Remaining Tasks: "<< endl;
        cout << "----------------------"<< endl;
        for (int i=0;i<task_count;i++)
        {
            cout << "Task"<<i+1<<" : "<<tasks[i]<<endl;
        }
        cout << "----------------------"<< endl;
    }

int main(){
    string tasks[10]={""};
    // add a counter variable
    int task_count=0;

    int option = -1;

    while (option != 0){
        //display menu options
        cout << "--TO DO LIST--" <<endl;
        cout << "Select one of the below options" <<endl;
        cout << "----------------------"<< endl;
        cout << "1 - To Add New Task" <<endl;
        cout << "2 - To View Tasks" <<endl;
        cout << "3 - To Remove a Task" <<endl;
        cout << "0 - To Terminate the program" <<endl;
        cout << "----------------------"<< endl;
        cin >> option;

        switch(option){
            case 1:
                {
               
                    if (task_count>9){
                    cout << "Sorry, Task list is full! Please remove a task to proceed" <<endl;
                }
                else {
                    cout << "Enter a new Task: ";
                    cin.ignore(); // to not accept empty input
                    getline(cin,tasks[task_count]); // to accept input as a string or line or paragraph
                    task_count++;
                }
                break;
                }
            case 2:
              
                print_tasks(tasks,task_count);
                break;

            case 3:
                {
              
                int del_task = 0;
                print_tasks(tasks,task_count);
                cout<< "Task count "<<task_count<<endl;
                cout << "Enter a task to delete: ";
                cin >> del_task;
                if (del_task>task_count || del_task<1)
                {

                    cout << "You have entered invalid task number\n";
                    break;
                }

                for (int i=del_task-1; i<task_count; i++)
                {
                    tasks[i]=tasks[i+1];
                }
                task_count=task_count-1;
                remaining_tasks(tasks,task_count);
                break;
                }

            case 0:
                cout << "------Terminating the program------" <<endl;
                break;

            default:
                cout << "You entered invalid option\n";
        }
    }

    return 0;
}
