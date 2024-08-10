#include <iostream>
#include <vector>

using namespace std;

#define N 9

// Function to check if a number can be placed in a given cell
bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    // Check the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& board) {
    int row = -1, col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
            break;
    }

    if (isEmpty)
        return true; // No empty space left, puzzle solved

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = 0; // Reset on backtrack
        }
    }

    return false; // Trigger backtracking
}

// Function to print the Sudoku board
void printBoard(vector<vector<int>>& board) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board))
        printBoard(board);
    else
        cout << "No solution exists!" << endl;

    return 0;
}
