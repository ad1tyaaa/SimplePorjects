#include <iostream>
#include <cstdlib>
#include <ctime>

int diceRoll()
{
    return 1 + (rand() % 6);
}

int main()
{
    // setting the seed
    srand(time(NULL));

    std::cout << "Roll a Dice Game" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Rules : press 1 to roll the dice. press 0 to exit." << std::endl;
    while (true)
    {
        int val;
        std::cout << "\nenter input : ";
        std::cin >> val;
        if (val == 0)
        {
            return 0;
        }
        else if (val == 1)
        {
            std::cout << "Dice Roll : " << diceRoll() << std::endl;
        }
        else
        {
            std::cout << "invalid Input. Try Again." << std::endl;
        }
    }
}

// learned about rand() and srand() functions.
// learned about time() and time_t datatype.
// srand() defines seed. time() returns the current time