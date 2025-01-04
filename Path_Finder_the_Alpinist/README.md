# Path Finder: Minimal Climb Rounds

## Problem Overview
You are tasked to find the minimal climb effort required to move from the top-left `[0, 0]` to the bottom-right `[N-1, N-1]` of an `N x N` grid, where the cost between two adjacent cells is the absolute difference in their altitudes.

## Algorithm Explanation

### 1. **Input Parsing**
The input string is converted into a 2D grid of integers. For example:
"010\n101\n010" -> grid = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}
### 2. **Dijkstra's Algorithm**
- **Priority Queue**: A min-heap is used to always process the cell with the smallest accumulated cost first.
- **Visited Matrix**: Tracks the minimal cost to reach each cell. Initially, all cells are set to infinity except the start position `[0, 0]`.
- **Pathfinding**:
  - Dequeue the cell with the smallest cost.
  - Explore its 4 neighbors (North, East, South, West).
  - Calculate the cost to reach a neighbor:  
    `new_cost = current_cost + abs(altitude_difference)`.
  - If the `new_cost` is smaller than the current cost for that neighbor, update and push it into the queue.
- **Terminate** when the target `[N-1, N-1]` is reached.

### 3. **Time Complexity**
- **Priority Queue Operations**: \(O(N^2 \log N)\), where \(N^2\) is the number of cells.
- **Neighbor Exploration**: \(O(N^2)\), as each cell has up to 4 neighbors.

**Total Time Complexity**:  
\(O(N^2 \log N)\).

This is near-optimal for this type of shortest-path problem.
