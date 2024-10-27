#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int rows;
    int cols;
    double** elements;

public:
    Matrix(int m, int n) : rows(m), cols(n) {
        elements = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            elements[i] = new double[cols]{0};
        }
    }

    void insertElement(double val, int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::out_of_range("Index out of range");
        }
        elements[i][j] = val;
    }

    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << elements[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] elements[i];
        }
        delete[] elements;
    }
};
