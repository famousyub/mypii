#include <iostream>
#include <vector>
#include <stack>

// Using a namespace to prevent potential naming conflicts and to logically group
// associated functionalities.
namespace MazeSolver {

    /**
    * @class Maze
    * Represents a maze grid and provides methods to solve it.
    */
    class Maze {
    private:
        std::vector<std::vector<int>> grid; // 2D vector to represent the maze grid
        int rows; // number of rows in the maze
        int cols; // number of columns in the maze

        /**
        * Checks if a given cell is a valid move in the maze.
        *
        * @param row The row index of the cell.
        * @param col The column index of the cell.
        * @return bool True if the cell is a valid move, false otherwise.
        */
        bool isValidMove(int row, int col) {
            // Check if the cell is within the maze boundaries and is not blocked (0)
            return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != 0);
        }

    public:
        /**
        * Constructs a maze with the provided grid.
        *
        * @param mazeGrid The 2D vector representing the maze grid.
        */
        Maze(std::vector<std::vector<int>> mazeGrid) {
            grid = mazeGrid;
            rows = mazeGrid.size();
            cols = mazeGrid[0].size();
        }

        /**
        * Solves the maze using Depth First Search (DFS) algorithm.
        *
        * @param startRow The row index of the starting cell.
        * @param startCol The column index of the starting cell.
        * @param endRow The row index of the target cell.
        * @param endCol The column index of the target cell.
        * @return bool True if a path is found, false otherwise.
        */
        bool solveMaze(int startRow, int startCol, int endRow, int endCol) {
            // Create a stack to store the visited cells
            std::stack<std::pair<int, int>> cellStack;

            // Create a 2D vector to keep track of visited cells
            std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

            // Push the starting cell onto the stack
            cellStack.push(std::make_pair(startRow, startCol));

            // Mark the starting cell as visited
            visited[startRow][startCol] = true;

            // Array to store the possible moves in the maze (up, down, left, right)
            int rowMoves[] = { -1, 1, 0, 0 };
            int colMoves[] = { 0, 0, -1, 1 };

            // Perform Depth First Search (DFS) until the stack is empty
            while (!cellStack.empty()) {
                // Get the current cell from the top of the stack
                int currentRow = cellStack.top().first;
                int currentCol = cellStack.top().second;
                cellStack.pop();

                // Check if the current cell is the target cell
                if (currentRow == endRow && currentCol == endCol) {
                    return true; // Path found!
                }

                // Visit all the neighboring cells
                for (int i = 0; i < 4; i++) {
                    int newRow = currentRow + rowMoves[i];
                    int newCol = currentCol + colMoves[i];

                    // Check if the neighboring cell is a valid move and has not been visited
                    if (isValidMove(newRow, newCol) && !visited[newRow][newCol]) {
                        // Push the neighboring cell onto the stack and mark it as visited
                        cellStack.push(std::make_pair(newRow, newCol));
                        visited[newRow][newCol] = true;
                    }
                }
            }

            return false; // No path found
        }
    };
}

int main() {
    // Example maze grid
    std::vector<std::vector<int>> mazeGrid = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    // Create a maze object with the maze grid
    MazeSolver::Maze maze(mazeGrid);

    // Solve the maze
    bool pathExists = maze.solveMaze(1, 1, 3, 3);

    // Print the result
    if (pathExists) {
        std::cout << "A path exists from the starting cell to the target cell.\n";
    }
    else {
        std::cout << "No path exists from the starting cell to the target cell.\n";
    }

    return 0;
}