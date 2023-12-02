#include <iostream>
#include <vector>

using namespace std;

bool is_valid_move(int row, int col, const vector<vector<char>> &board, vector<vector<bool>> &visited) {
    int rows = board.size();
    int cols = board[0].size();

    return (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row][col]);
}

bool search_word(int row, int col, const vector<vector<char>> &board, const string &word, int index, vector<vector<bool>> &visited) {
    if (index == word.length()) {
        return true; // Successfully found the entire word
    }

    static const int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int dir = 0; dir < 8; ++dir) {
        int newRow = row + directions[dir][0];
        int newCol = col + directions[dir][1];

        if (is_valid_move(newRow, newCol, board, visited) && board[newRow][newCol] == word[index]) {
            visited[newRow][newCol] = true;

            if (search_word(newRow, newCol, board, word, index + 1, visited)) {
                return true; // Word found in this direction
            }

            visited[newRow][newCol] = false; // Backtrack
        }
    }

    return false; // Word not found
}

bool check_word(const vector<vector<char>> &board, const string &word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == word[0]) {
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                visited[i][j] = true;

                if (search_word(i, j, board, word, 1, visited)) {
                    return true; // Word found starting from this position
                }
            }
        }
    }

    return false; // Word not found on the board
}
