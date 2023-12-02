#include <iostream>
#include <vector>

using namespace std;

bool isValidCell(int row, int col, int numRows, int numCols, vector<vector<bool>>& visited) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols && !visited[row][col];
}

bool isValidGuess(const vector<vector<char>>& board, const string& word, int row, int col, int index, vector<vector<bool>>& visited) {
    if (index == word.length()) {
        return true;
    }

    if (!isValidCell(row, col, board.size(), board[0].size(), visited) || board[row][col] != word[index]) {
        return false;
    }

    visited[row][col] = true;

    // Explore adjacent cells
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (isValidGuess(board, word, row + i, col + j, index + 1, visited)) {
                visited[row][col] = false;  // Backtrack: mark the current cell as unvisited
                return true;
            }
        }
    }

    visited[row][col] = false;  // Backtrack: mark the current cell as unvisited
    return false;
}

bool check_word(const vector<vector<char>>& board, const string& word) {
    int numRows = board.size();
    int numCols = board[0].size();

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
            if (isValidGuess(board, word, i, j, 0, visited)) {
                return true;
            }
        }
    }

    return false;
}

