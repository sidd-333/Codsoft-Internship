#include <iostream>
using namespace std;
const int SIZE = 3;
char GameBoard[SIZE][SIZE];
void initializeGameBoard()
{
    char initial = '1';
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            GameBoard[i][j] = initial++;
        }
    }
}
void displayGameBoard()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << GameBoard[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkWin(char player)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if ((GameBoard[i][0] == player && GameBoard[i][1] == player && GameBoard[i][2] == player) ||
            (GameBoard[0][i] == player && GameBoard[1][i] == player && GameBoard[2][i] == player))
        {
            return true;
        }
    }
    if ((GameBoard[0][0] == player && GameBoard[1][1] == player && GameBoard[2][2] == player) ||
        (GameBoard[0][2] == player && GameBoard[1][1] == player && GameBoard[2][0] == player))
    {
        return true;
    }
    return false;
}
bool checkDraw()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (GameBoard[i][j] != 'X' && GameBoard[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}
bool makeMove(char player, int move)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    if (GameBoard[row][col] != 'X' && GameBoard[row][col] != 'O')
    {
        GameBoard[row][col] = player;
        return true;
    }
    else
    {
        cout << "Invalid move. Try again." << endl;
        return false;
    }
}
bool playGame()
{
    initializeGameBoard();
    char currentPlayer = 'X';
    int move;
    while (true)
    {
        displayGameBoard();
        cout << "Player " << currentPlayer << ", Enter your move between 1 to 9: ";
        cin >> move;
        if (move < 1 || move > 9)
        {
            cout << "Invalid input. Enter a number between 1 and 9." << endl;
            continue;
        }
        if (makeMove(currentPlayer, move))
        {
            if (checkWin(currentPlayer))
            {
                displayGameBoard();
                cout << "Player " << currentPlayer << " Wins!" << endl;
                return true;
            }
            else if (checkDraw())
            {
                displayGameBoard();
                cout << "The game is a Draw!" << endl;
                return true;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}
int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play another game? (yes/no): ";
        cin >> playAgain;
    } while (playAgain == 'yes' || playAgain == 'Yes');
    cout << "Thanks for playing!" << endl;
    return 0;
}

