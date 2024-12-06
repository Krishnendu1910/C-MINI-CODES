#include <iostream>
#include <vector>
using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; // Empty space means game is not over
        }
    }
    return true; // No empty spaces and no winner means draw
}

// Main function
int main() {
    char playAgain = 'y';
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board
        char currentPlayer = 'X'; // Start with Player 'X'
        bool gameWon = false;

        cout << "Let's start the game!" << endl;
        displayBoard(board);

        while (true) {
            // Player input
            int row, col;
            cout << "Player " << currentPlayer << "'s turn." << endl;
            cout << "Enter row (1-3) and column (1-3): ";
            cin >> row >> col;
            row--; col--; // Adjust for 0-based indexing

            // Validate input
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            // Update board
            board[row][col] = currentPlayer;
            displayBoard(board);

            // Check for win
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameWon = true;
                break;
            }

            // Check for draw
            if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;
    return 0;
}
