#include <iostream>
#include <vector>
#include <limits>

namespace HungarianAlgorithm {

    /**
    * @class AssignmentProblemSolver
    * Solves the assignment problem using the Hungarian algorithm.
    */
    class AssignmentProblemSolver {
    private:
        std::vector<std::vector<int>> costMatrix;
        int numRows;
        int numCols;

        /**
        * Builds the cost matrix using the provided array, number of rows, and number of columns.
        *
        * @param costArray The array representing the cost matrix.
        * @param numRows The number of rows in the cost matrix.
        * @param numCols The number of columns in the cost matrix.
        */
        void buildCostMatrix(const std::vector<int>& costArray, int numRows, int numCols) {
            costMatrix.resize(numRows, std::vector<int>(numCols));

            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numCols; j++) {
                    costMatrix[i][j] = costArray[i * numCols + j];
                }
            }
        }

        /**
        * Finds the minimum value in a given row of the cost matrix.
        *
        * @param row The row index.
        * @return int The minimum value in the row.
        */
        int findMinInRow(int row) {
            int minValue = std::numeric_limits<int>::max();

            for (int j = 0; j < numCols; j++) {
                if (costMatrix[row][j] < minValue) {
                    minValue = costMatrix[row][j];
                }
            }

            return minValue;
        }

        /**
        * Finds the minimum value in a given column of the cost matrix.
        *
        * @param col The column index.
        * @return int The minimum value in the column.
        */
        int findMinInCol(int col) {
            int minValue = std::numeric_limits<int>::max();

            for (int i = 0; i < numRows; i++) {
                if (costMatrix[i][col] < minValue) {
                    minValue = costMatrix[i][col];
                }
            }

            return minValue;
        }

    public:
        /**
        * Constructs an AssignmentProblemSolver object with the provided cost matrix dimensions.
        *
        * @param numRows The number of rows in the cost matrix.
        * @param numCols The number of columns in the cost matrix.
        */
        AssignmentProblemSolver(int numRows, int numCols) {
            this->numRows = numRows;
            this->numCols = numCols;
        }

        /**
        * Solves the assignment problem using the Hungarian algorithm.
        *
        * @param costArray The array representing the cost matrix.
        * @param numRows The number of rows in the cost matrix.
        * @param numCols The number of columns in the cost matrix.
        * @return std::vector<int> The assignment vector, where each element represents the assigned column index for the corresponding row.
        */
        std::vector<int> solve(const std::vector<int>& costArray, int numRows, int numCols) {
            buildCostMatrix(costArray, numRows, numCols);

            std::vector<int> assignment(numRows, -1);
            std::vector<bool> rowCovered(numRows, false);
            std::vector<bool> colCovered(numCols, false);

            int numCovered = 0;

            while (numCovered < numRows) {
                // Step 1: Subtract the minimum value in each row from all elements in that row.
                for (int i = 0; i < numRows; i++) {
                    int minInRow = findMinInRow(i);

                    for (int j = 0; j < numCols; j++) {
                        costMatrix[i][j] -= minInRow;
                    }
                }

                // Step 2: Subtract the minimum value in each column from all elements in that column.
                for (int j = 0; j < numCols; j++) {
                    int minInCol = findMinInCol(j);

                    for (int i = 0; i < numRows; i++) {
                        costMatrix[i][j] -= minInCol;
                    }
                }

                // Step 3: Cover all zeros with minimum number of horizontal and vertical lines.
                for (int i = 0; i < numRows; i++) {
                    for (int j = 0; j < numCols; j++) {
                        if (costMatrix[i][j] == 0 && !rowCovered[i] && !colCovered[j]) {
                            assignment[i] = j;
                            rowCovered[i] = true;
                            colCovered[j] = true;
                            numCovered++;
                            break;
                        }
                    }
                }

                if (numCovered == numRows) {
                    break;
                }

                // Step 4: Find an uncovered zero and prime it.
                std::vector<bool> markedRows(numRows, false);
                std::vector<bool> markedCols(numCols, false);
                int row = -1;
                int col = -1;
                bool foundZero = false;

                while (!foundZero) {
                    for (int i = 0; i < numRows; i++) {
                        if (!rowCovered[i] && !markedRows[i]) {
                            for (int j = 0; j < numCols; j++) {
                                if (!colCovered[j] && !markedCols[j] && costMatrix[i][j] == 0) {
                                    row = i;
                                    col = j;
                                    foundZero = true;
                                    break;
                                }
                            }
                        }

                        if (foundZero) {
                            break;
                        }
                    }

                    if (!foundZero) {
                        // Step 5: Find the minimum uncovered value and subtract it from all uncovered values.
                        int minUncovered = std::numeric_limits<int>::max();

                        for (int i = 0; i < numRows; i++) {
                            if (!rowCovered[i]) {
                                for (int j = 0; j < numCols; j++) {
                                    if (!colCovered[j] && costMatrix[i][j] < minUncovered) {
                                        minUncovered = costMatrix[i][j];
                                    }
                                }
                            }
                        }

                        for (int i = 0; i < numRows; i++) {
                            if (rowCovered[i]) {
                                for (int j = 0; j < numCols; j++) {
                                    costMatrix[i][j] += minUncovered;
                                }
                            }
                        }

                        for (int j = 0; j < numCols; j++) {
                            if (!colCovered[j]) {
                                for (int i = 0; i < numRows; i++) {
                                    costMatrix[i][j] -= minUncovered;
                                }
                            }
                        }
                    }
                }

                // Step 6: Add the marked rows to the covered rows and remove the marked columns from the covered columns.
                for (int i = 0; i < numRows; i++) {
                    if (markedRows[i]) {
                        rowCovered[i] = true;
                    }
                }

                for (int j = 0; j < numCols; j++) {
                    if (markedCols[j]) {
                        colCovered[j] = false;
                    }
                }
            }

            return assignment;
        }
    };
}

int main() {
    // Example usage of the AssignmentProblemSolver class
    {
        std::vector<int> costArray = { 3, 1, 4, 2, 8, 5, 6, 7, 9 }; // Cost matrix represented as a single array
        int numRows = 3;
        int numCols = 3;

        HungarianAlgorithm::AssignmentProblemSolver solver(numRows, numCols);
        std::vector<int> assignment = solver.solve(costArray, numRows, numCols);

        std::cout << "Assignment: ";
        for (int i = 0; i < numRows; i++) {
            std::cout << "(" << i << ", " << assignment[i] << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}