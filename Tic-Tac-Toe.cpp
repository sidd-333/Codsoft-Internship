#include <iostream>
using namespace std;
const int SIZE = 3;
char board[SIZE][SIZE];
void initializeBoard() {
    char initial = '1';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = initial++;
        }
    }
}
void displayBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
             cout << board[i][j] << " ";
        }
         cout <<  endl;
    }
}
bool checkWin(char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}
bool makeMove(char player, int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    } else {
         cout << "Invalid move. Try again." <<  endl;
        return false;
    }
}
bool playGame() {
    initializeBoard();
    char currentPlayer = 'X';
    int move;
    while (true) {
        displayBoard();
         cout << "Player " << currentPlayer << ", enter your move (1-9): ";
         cin >> move;
        if (move < 1 || move > 9) {
             cout << "Invalid input. Enter a number between 1 and 9." <<  endl;
            continue;
        }
        if (makeMove(currentPlayer, move)) {
            if (checkWin(currentPlayer)) {
                displayBoard();
                 cout << "Player " << currentPlayer << " wins!" <<  endl;
                return true;
            } else if (checkDraw()) {
                displayBoard();
                 cout << "The game is a draw!" <<  endl;
                return true;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}
int main() {
    char playAgain;
    do {
        playGame();
         cout << "Do you want to play another game? (y/n): ";
         cin >> playAgain;
    } 
    while (playAgain == 'y' || playAgain == 'Y');
        cout << "Thanks for playing!" <<  endl;
    return 0;
}
