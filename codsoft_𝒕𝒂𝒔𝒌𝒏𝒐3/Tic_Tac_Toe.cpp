#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << std::endl;
}

// Function to check if there's a winner
char checkWinner(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    // No winner yet
    return ' ';
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        // Display the board
        displayBoard(board);

        // Player input
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Update the board
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check for a winner
            char winner = checkWinner(board);
            if (winner != ' ') {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check for a draw
            bool isDraw = true;
            for (const auto& row : board) {
                for (char cell : row) {
                    if (cell == ' ') {
                        isDraw = false;
                        break;
                    }
                }
                if (!isDraw) break;
            }
            if (isDraw) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    } while (true);

    std::cout << "Thanks for playing!\n";

    return 0;
}
