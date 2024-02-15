#include <iostream>
#include <vector>

struct myStruct
{
    std::vector<std::string> tasks;
    std::vector<bool> isFinished;
};

void unfinishedTaskOption(std::vector<std::string> &tasks, std::vector<bool> &isFinished);

void createTask(std::vector<std::string> &tasks, std::vector<bool> &isFinished)
{
    std::string task;
    std::cout << "\nEnter Task Name : ";
    std::cin >> task;
    tasks.push_back(task);
    isFinished.push_back(0);
    std::cout << "> A new Task called \"" << tasks[tasks.size() - 1] << "\" has been created and marked as unfinished." << std::endl;
}

void finishTask(std::vector<std::string> &tasks, std::vector<bool> &isFinished)
{
    int val;
    std::cout << "\nSelect task to mark finished : ";
    std::cin >> val;
    int i = 0;
    for (; i < isFinished.size(); i++)
    {
        if (isFinished[i] == 0)
        {
            val--;
        }
        if (val == 0)
        {
            break;
        }
    }
    std::cout << "\ni : " << i << std::endl;
    // now I'll mark the task finished.
    isFinished[i] = 1;
    std::cout << "\n> \"" << tasks[i] << "\" has been marked as finished." << std::endl;
    std::cout << "\nDo you want to finish another task ? " << std::endl;
}

void unfinishedTaskOption(std::vector<std::string> &tasks, std::vector<bool> &isFinished)
{
    int val;
    std::cout << "\n(1) Finish a Task    (2) Go Back" << std::endl;
    std::cout << "input : ";
    std::cin >> val;
    if (val == 1)
    {
        finishTask(tasks, isFinished);
    }
    else if (val == 2)
    {
        return;
    }
    else
    {
        std::cout << "Ivalid Input." << std::endl;
    }
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
            unfinishedTaskOption(tasks, isFinished);
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

// there a two problems in this code.
// fix them later.
