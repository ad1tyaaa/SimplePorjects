#include <iostream>
#include <cstdlib>
#include <ctime>

void startGame()
{

    // generating the random number
    srand(time(NULL));
    int randomNumber = 1 + rand() % 10;

    // HACK
    std::cout << "random number : " << randomNumber << std::endl;

    int attempts = 0;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nattempt : " << attempts + 1 << std::endl;
        std::cout << "What's your guess ? ";
        int guess;
        std::cin >> guess;
        if (guess == randomNumber)
        {
            std::cout << "\nYou guessed the correct number. YOU WIN. CONGRATULATIONS." << std::endl;
            std::cout << "Play Again ?\n"
                      << std::endl;
            return;
        }
        else if (guess > randomNumber)
        {
            std::cout << "\nWrong Guess.";
            if (i != 2)
            {
                std::cout << " Think of a smaller number." << std::endl;
            }
            attempts++;
        }
        else
        {
            std::cout << "\nWrong Guess.";
            if (i != 2)
            {
                std::cout << " Think of a bigger number." << std::endl;
            }
            attempts++;
        }
    }
    std::cout << "\n\nYou don't have any remaining attempts. Game Over." << std::endl;
    std::cout << "Start Again ?\n"
              << std::endl;
}

int main()
{
    std::cout << "Guess the Number Game" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Rules : " << std::endl;
    std::cout << "I will generate a random between 1 to 10." << std::endl;
    std::cout << "You will get 3 attempts to guess the random number." << std::endl;
    std::cout << "On every guess, I will tell you, if the correct answer is towards the left or right of your guess.\n"
              << std::endl;

    while (true)
    {
        int val;
        std::cout << "(1) Start GAME    (0) Exit GAME" << std::endl;
        std::cout << "Input : ";
        std::cin >> val;
        if (val == 1)
        {
            startGame();
        }
        else if (val == 0)
        {
            return 0;
        }
        else
        {
            std::cout << "Invalid Input." << std::endl;
        }
    }
    return 0;
}