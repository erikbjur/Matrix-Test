#include <iostream>
#include <memory>
#include <stdexcept>

// This is a longer version that works just fine
/*template <typename T> class Matrix {
public:
  Matrix(size_t rows, size_t cols)
      : rows_(rows), cols_(cols), data_(std::make_unique<T[]>(rows * cols)) {}

  // Access the row as an array
  class Row {
  public:
    Row(T *rowData, size_t cols) : rowData_(rowData), cols_(cols) {}

    T &operator[](size_t col) {
      if (col >= cols_) {
        throw std::out_of_range("Column index out of range");
      }
      return rowData_[col];
    }

    const T &operator[](size_t col) const {
      if (col >= cols_) {
        throw std::out_of_range("Column index out of range");
      }
      return rowData_[col];
    }

  private:
    T *rowData_;
    size_t cols_;
  };

  // Access the row
  Row operator[](size_t row) {
    if (row >= rows_) {
      throw std::out_of_range("Row index out of range");
    }
    return Row(&data_[row * cols_], cols_);
  }

  // Const access for read-only
  const Row operator[](size_t row) const {
    if (row >= rows_) {
      throw std::out_of_range("Row index out of range");
    }
    return Row(&data_[row * cols_], cols_);
  }

  // Optional: Function to print the matrix
  void print() const {
    for (size_t i = 0; i < rows_; ++i) {
      for (size_t j = 0; j < cols_; ++j) {
        std::cout << (*this)[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

private:
  size_t rows_;
  size_t cols_;
  std::unique_ptr<T[]> data_; // Single block of memory
};
*/

// This is a shorter version but I can't figure out why [x][y] works.
template <typename T> class Matrix {
public:
  // Constructor to initialize the matrix with given rows and columns
  Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
    // Allocate memory for a 2D matrix using a single block of memory
    data_ = std::make_unique<T[]>(m_rows * m_cols);
  }

  // Destructor automatically frees the memory managed by unique_ptr
  ~Matrix() = default;

  // Overload the [] operator for row access
  T *operator[](size_t row) {
    if (row >= m_rows) {
      throw std::out_of_range("Row index out of bounds");
    }
    // Return a pointer to the beginning of the specified row
    return &data_[row * m_cols];
  }

  // Overload the const [] operator for const row access
  const T *operator[](size_t row) const {
    if (row >= m_rows) {
      throw std::out_of_range("Row index out of bounds");
    }
    // Return a const pointer to the beginning of the specified row
    return &data_[row * m_cols];
  }

  void print() const {
    for (size_t i = 0; i < m_rows; ++i) {
      for (size_t j = 0; j < m_cols; ++j) {
        std::cout << (*this)[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

private:
  size_t m_rows;              // Number of rows in the matrix
  size_t m_cols;              // Number of columns in the matrix
  std::unique_ptr<T[]> data_; // Unique pointer to manage the 2D matrix memory
};