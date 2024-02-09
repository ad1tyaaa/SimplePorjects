#include <iostream>
#include <cstdlib>
#include <ctime>

// 1 -> Rock, 2 -> Paper, 3 -> Scissors.

int computerIsPlaying()
{
    // randomly choosing between Rock, Paper, or Scissor
    srand(time(NULL));
    int val = 1 + rand() % 3;
    return val;
}

int humanIsPlaying()
{
    int val;
    std::cout << "\nChoose : ";
    std::cout << "(1) ROCK    (2) PAPER    (3) SCISSOR" << std::endl;
    std::cout << "input : ";
    std::cin >> val;
    return val;
}

int checkWinner(int human, int computer)
{
    if (human == computer)
    {
        return 0;
    }
    else if ((human == 1 && computer == 3) || (human == 2 && computer == 1) || (human == 3 && computer == 2))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

std::string choice(int val)
{
    if (val == 1)
    {
        return "ROCK";
    }
    else if (val == 2)
    {
        return "PAPER";
    }
    else
    {
        return "SCISSORS";
    }
}

void startGame()
{
    int humanScore = 0, computerScore = 0;
    int round = 1;
    while ((humanScore < 5) && (computerScore < 5))
    {
        std::cout << "\n===============================================" << std::endl;
        std::cout << "\nROUND : " << round << std::endl;
        std::cout << "\nSCORECARD : Human = " << humanScore << "     Computer = " << computerScore << std::endl;
        int computer = computerIsPlaying();
        int human = humanIsPlaying();
        if (checkWinner(human, computer) == 0)
        {
            std::cout << "\nDRAW. We both chose " << choice(human) << "." << std::endl;
        }
        else if (checkWinner(human, computer) == 1)
        {
            std::cout << "\nYou WIN. You chose " << choice(human) << " and I chose " << choice(computer) << "." << std::endl;
            humanScore++;
        }
        else
        {
            std::cout << "\nI WIN. You chose " << choice(human) << " and I chose " << choice(computer) << "." << std::endl;
            computerScore++;
        }
        std::cout << "\n===============================================" << std::endl;
        round++;
    }
    if (humanScore == 5)
    {
        std::cout << "\nYOU WON THE GAME. CONGRATULATIONS!!" << std::endl;
    }
    else
    {
        std::cout << "\nI WON THE GAME. BETTER LUCK NEXT TIME." << std::endl;
    }
    std::cout << "\nDo you want to play again ?" << std::endl;
}

int main()
{
    std::cout << "\nROCK - PAPER - SCISSORS" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "\nDo you want to play Rock-Paper-Scissors with me ?" << std::endl;

    while (true)
    {
        int val;
        std::cout << "\n(1) YES, Let's Play.    (0) NO, I'm Out." << std::endl;
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
            std::cout << "\ninvalid Input. Try Again." << std::endl;
        }
    }
}