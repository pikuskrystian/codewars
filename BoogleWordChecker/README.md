# Boggle Board Word Search

This C++ code implements a Boggle board word search algorithm. It uses recursive backtracking to explore all possible paths on the Boggle board and checks if a given word can be formed.

## Functions

### 1. `is_valid_move` Function:

```cpp
bool is_valid_move(int row, int col, const vector<vector<char>> &board, vector<vector<bool>> &visited)
```
-Purpose: Checks if a move to the specified (row, col) is valid, considering the board boundaries and whether the cell has been visited.
-Parameters: row, col: Coordinates of the cell to check. board: The Boggle board. visited: Matrix indicating visited cells.
-Return Value: Returns true if the move is valid; otherwise, returns false.

### 2. `search_word` Function:
```cpp
bool search_word(int row, int col, const vector<vector<char>> &board, const string &word, int index, vector<vector<bool>> &visited)
```
-Purpose: Recursively searches for the given word starting from a specific cell.
-Parameters: row, col: Current cell coordinates. board: The Boggle board. word: The word to search for. index: The index of the current character in the word. visited: Matrix indicating visited cells.
-Return Value: Returns true if the entire word is found starting from the current cell; otherwise, returns false.

### 3. `check_word` Function:
```cpp
bool check_word(const vector<vector<char>> &board, const string &word)
```
-Purpose: Checks if the given word can be formed on the Boggle board.
-Parameters: board: The Boggle board. word: The word to search for.
-Return Value: Returns true if the word can be formed on the board; otherwise, returns false.

### 4. Main Algorithm (in check_word):
Iterate Through the Board:

Use nested loops to iterate through each cell on the Boggle board.
Check First Character Match:

Check if the current cell's character matches the first character of the word.
If not, move to the next cell.
Initialize Visited Matrix:

Create a matrix (visited) to track visited cells and mark the current cell as visited.
Search for the Word:

Call the search_word function to search for the word starting from the current cell.
If search_word returns true, the entire word is found, and the function returns true.
If not found, move to the next cell.
Return Result:

If the word is found starting from any cell, the function returns true.
If the entire board is searched, and the word is not found, the function returns false.
### 5. search_word Algorithm:
Base Case:

If the index reaches the length of the word, the entire word is found, and the function returns true.
Explore Adjacent Cells:

Use predefined directions to explore adjacent cells in eight directions (horizontal, vertical, and diagonal).
Check Valid Move and Character Match:

Check if the move to the adjacent cell is valid (within board boundaries and not visited).
Check if the character in the adjacent cell matches the next character in the word.
Recursive Call:

If the conditions are met, mark the cell as visited, and recursively call search_word with updated parameters.
If the recursive call returns true, propagate the success back.
If not, backtrack by marking the cell as not visited.
Backtracking:

After exploring all directions, return false to backtrack to the previous state.
This code uses recursive backtracking to explore all possible paths on the Boggle board to find a match for the given word. The functions work together to check if the word can be formed on the board.
