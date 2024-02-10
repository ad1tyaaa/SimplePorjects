#include <iostream>
#include <vector>
#include <string>

void createTask(std::vector<std::string> &tasks, std::vector<bool> &isFinished)
{
    std::string task;
    std::cout << "\nEnter Task Name : ";
    // instead of using cin, use getline for this.
    // currently, only a single words can be input. Fix that.
    std::cin >> task;
    // getline(std::cin, task); this is not working idk why
    tasks.push_back(task);
    isFinished.push_back(0);
    std::cout << "> A new Task called \"" << tasks[tasks.size() - 1] << "\" has been created and marked as unfinished." << std::endl;
    // add code to save the task & isFinished array in an file.
}

void seeTasks(std::vector<std::string> &tasks, std::vector<bool> &isFinished)
{
    int val;
    std::cout << "\n(1) See Unfinished Tasks     (2) See Finished Tasks" << std::endl;
    std::cout << "input : ";
    std::cin >> val;
    if (val == 1)
    {
        // see unfinished tasks.
        std::cout << "\nAll Unfinished Tasks : " << std::endl;
        int unfinishedCount = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (isFinished[i] == 0)
            {
                std::cout << unfinishedCount + 1 << ". " << tasks[i] << std::endl;
                unfinishedCount++;
            }
        }
        if (unfinishedCount == 0)
        {
            std::cout << "\n> You don't have any unfinished tasks. Create a task and come back." << std::endl;
        }
        else
        {
            std::cout << "\n> You have " << unfinishedCount << " tasks remaining." << std::endl;
        }
    }
    else if (val == 2)
    {
        // see finished tasks.
        std::cout << "\nAll Finished Tasks : " << std::endl;
        int finishedCount = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (isFinished[i] == 1)
            {
                std::cout << finishedCount + 1 << ". " << tasks[i] << std::endl;
                finishedCount++;
            }
        }
        if (finishedCount == 0)
        {
            std::cout << "\n> You don't have any finished tasks. Create a task and finish it and then come back." << std::endl;
        }
        else
        {
            std::cout << "\n> You have finished " << finishedCount << " tasks. Wow!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid Input. Try Again." << std::endl;
        seeTasks(tasks, isFinished);
    }
    // add code to mark a task as finished.
    // add code to delete a task.
    // add to read the tasks & infinished arrays from a file.
    // add code to save the changes in the tasks & isFinished arrays to a file.
}

void startProgram()
{
    int val;
    std::vector<std::string> tasks;
    std::vector<bool> isFinished;
    while (true)
    {
        std::cout << "\n(0) EXIT    (1) See Tasks    (2) Create new Task" << std::endl;
        std::cout << "input : ";
        std::cin >> val;
        if (val == 0)
        {
            return;
        }
        else if (val == 1)
        {
            seeTasks(tasks, isFinished);
        }
        else if (val == 2)
        {
            createTask(tasks, isFinished);
        }
        else
        {
            std::cout << "\nInvalid Input. Try Again." << std::endl;
        }
    }
}

int main()
{
    std::cout << "\nTo-Do List Application" << std::endl;
    std::cout << "----------------------" << std::endl;
    startProgram();
}