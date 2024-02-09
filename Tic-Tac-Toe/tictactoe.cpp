#include <iostream>

// print the currnt state of game on the baord
char printElement(char arr[], int i)
{
    if ((arr[i] == 'X') || (arr[i] == 'O'))
    {
        return arr[i];
    }
    else
        return ' ';
}

// prints the board after every turn
void printBoard(char arr[], int size)
{
    std::cout << "\n ----------- " << std::endl;
    std::cout << "| " << printElement(arr, 0) << " | " << printElement(arr, 1) << " | " << printElement(arr, 2) << " |" << std::endl;
    std::cout << " ----------- " << std::endl;
    std::cout << "| " << printElement(arr, 3) << " | " << printElement(arr, 4) << " | " << printElement(arr, 5) << " |" << std::endl;
    std::cout << " ----------- " << std::endl;
    std::cout << "| " << printElement(arr, 6) << " | " << printElement(arr, 7) << " | " << printElement(arr, 8) << " |" << std::endl;
    std::cout << " ----------- " << std::endl;
}

// check for win conditions after every move.
// 0 -> Continue with game.
// 1 -> 'X' wins the game.
// 2 -> 'O' wins the game.
// 3 -> Game Draw. No one won.
int status(char arr[], int size)
{
    // checking horizontal win conditions
    for (int i = 0; i < 3; i++)
    {
        if ((arr[3 * i] == arr[3 * i + 1]) && (arr[3 * i + 1] == arr[3 * i + 2]) && (arr[3 * i] == 'X'))
        {
            return 1;
        }
        else if ((arr[3 * i] == arr[3 * i + 1]) && (arr[3 * i + 1] == arr[3 * i + 2]) && (arr[3 * i] == 'O'))
        {
            return 2;
        }
    }
    // checking vertical win conditions
    for (int i = 0; i < 3; i++)
    {
        if ((arr[i] == arr[3 + i]) && (arr[3 + i] == arr[6 + i]) && (arr[i] == 'X'))
        {
            return 1;
        }
        else if ((arr[i] == arr[3 + i]) && (arr[3 + i] == arr[6 + i]) && (arr[i] == 'O'))
        {
            return 2;
        }
    }
    // checking diagonal win condition
    if (((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[4] == 'X')) || ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[4] == 'X')))
    {
        return 1;
    }
    else if (((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[4] == 'O')) || ((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[4] == 'O')))
    {
        return 2;
    }
    // check for draw
    int moves = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((arr[i] == 'O') || (arr[i] == 'X'))
        {
            moves++;
        }
    }
    if (moves == 9)
    {
        return 3;
    }
    // if every condition fails, continue game.
    return 0;
};

// prevent overwritting the same box with a new value.
bool isOverwritting(char arr[], int size, int pos)
{
    if (arr[pos] == 'X' || (arr[pos] == 'O'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// When the turn of a player comes, they can mark one box on the Board.
void playerTurn(bool player, char arr[], int size)
{
    int val;
    if (player == 0)
    {
        std::cout << "\nPlayer 1's turn (X) : ";
        std::cin >> val;
        if (isOverwritting(arr, 9, val - 1))
        {
            std::cout << "You are not allowed to do that. Try Again." << std::endl;
            playerTurn(player, arr, size);
        }
        else
        {
            arr[val - 1] = 'X';
        }
    }
    else
    {
        std::cout << "\nPlayer 2's turn (O) : ";
        std::cin >> val;
        if (isOverwritting(arr, 9, val - 1))
        {
            std::cout << "You are not allowed to do that. Try Again." << std::endl;
            playerTurn(player, arr, size);
        }
        else
        {
            arr[val - 1] = 'O';
        }
    }
}

// The game.
void startGame()
{
    char arr[9];
    bool player = 1;
    while (status(arr, 9) == 0)
    {
        printBoard(arr, 9);
        player = !player; // changing player
        playerTurn(player, arr, 9);
    }
    printBoard(arr, 9);
    if (status(arr, 9) == 1)
    {
        std::cout << "\nPlayer 1 (X) Wins." << std::endl;
    }
    else if (status(arr, 9) == 2)
    {
        std::cout << "\nPlayer 2 (O) Wins." << std::endl;
    }
    else
    {
        std::cout << "\nGame Draw. No on Wins." << std::endl;
    }
}

int main()
{
    std::cout << "\nTIC-TAC-TOE GAME" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "\nRules : " << std::endl;
    std::cout << "Player 1 is (X) and Player 2 is (O).\nAll the boxes are numbered from 1 to 9."
              << std::endl;

    while (true)
    {
        int val;
        std::cout << "\n(1) PLAY GAME    (0) EXIT GAME" << std::endl;
        std::cout << "enter input : ";
        std::cin >> val;
        if (val == 1)
        {
            startGame();
            std::cout << "\nWould you like to play again ?" << std::endl;
        }
        else if (val == 0)
        {
            return 0;
        }
        else
        {
            std::cout << "Invalid Input. Try Again." << std::endl;
        }
    }
}