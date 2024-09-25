#include "matrix.h"
#include <iostream>

int main() {
  // Example usage
  size_t rows = 3, cols = 4;

  // Create a 3x4 matrix
  Matrix<double> matrix(rows, cols);

  // Set values in the matrix using [] operator
  int counter = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      matrix[i][j] = counter++;
    }
  }

  /*// Print the matrix using [] operator
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }*/

  matrix.print();

  // Example of setting a value using [] operator
  matrix[1][2] = 0; // Set the value at row 2, column 2 to 5

  // Print the modified matrix
  std::cout << "Modified matrix:" << std::endl;
  /*for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }*/
  matrix.print();

  std::cout << "Now printing the value stored at Matrix[1][3]: ";
  std::cout << matrix[1][3] << std::endl;

  return 0;
}