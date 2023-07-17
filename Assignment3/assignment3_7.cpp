// Aritra Bandyopadhyay 2021CSB107
// Assignment3_7 Implementation of Matrix Class
#include <bits/stdc++.h>
using namespace std;

class Matrix {
    public:
        Matrix(const vector<vector<double>> &data) : data_(data), rows_(data.size()), cols_(data[0].size()) {}

        vector<vector<double>> data_;
        int rows_;
        int cols_;

        Matrix operator+(const Matrix &other) const {
            if (rows_ != other.rows_ || cols_ != other.cols_) {
                throw invalid_argument("Matrices have different dimensions.");
            }

            vector<vector<double>> result(rows_, vector<double>(cols_));
            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                result[i][j] = data_[i][j] + other.data_[i][j];
                }
            }

            return Matrix(result);
        }

        Matrix operator*(const Matrix &other) const {
            if (cols_ != other.rows_) {
                throw invalid_argument("Inner dimensions don't match.");
            }

            vector<vector<double>> result(rows_, vector<double>(other.cols_));
            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < other.cols_; ++j) {
                for (int k = 0; k < cols_; ++k) {
                    result[i][j] += data_[i][k] * other.data_[k][j];
                }
                }
            }

            return Matrix(result);
        }

        bool operator==(const Matrix &other) const {
            if (rows_ != other.rows_ || cols_ != other.cols_) {
                return false;
            }

            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                if (data_[i][j] != other.data_[i][j]) {
                    return false;
                }
                }
            }

            return true;
        }

        Matrix transpose() const {
            vector<vector<double>> result(cols_, vector<double>(rows_));
            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                result[j][i] = data_[i][j];
                }
            }

            return Matrix(result);
        }

        Matrix sub_matrix(int row, int col) const {
            vector<vector<double>> result(rows_ - 1, vector<double>(cols_ - 1));
            int new_row = 0;
            for (int i = 0; i < rows_; ++i) {
                if (i ==row) {
                continue;
                }
                int new_col = 0;
                for (int j = 0; j < cols_; ++j) {
                if (j == col) {
                    continue;
                }
                result[new_row][new_col++] = data_[i][j];
                }
                ++new_row;
            }

            return Matrix(result);
        }

        Matrix inverse() const {
            double det = determinant();
            if (det == 0) {
                throw invalid_argument("Matrix is not invertible.");
            }

            vector<vector<double>> result(rows_, vector<double>(cols_));
            for (int i = 0; i < rows_; ++i) {
                for (int j = 0; j < cols_; ++j) {
                result[i][j] = pow(-1, i + j) * sub_matrix(j, i).determinant() / det;
                }
            }

            return Matrix(result);
        }

        double determinant() const {
            if (rows_ != cols_) {
                throw invalid_argument("Matrix is not square.");
            }

            if (rows_ == 1) {
                return data_[0][0];
            }

            if (rows_ == 2) {
                return data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0];
            }

            double det = 0;
            for (int i = 0; i < cols_; ++i) {
                det += pow(-1, i) * data_[0][i] * sub_matrix(0, i).determinant();
            }

            return det;
        }
        void print() const {
            for (const auto& row : data_) {
                for (const auto& elem : row) {
                    cout << elem << " ";
                }
                cout << endl;
            }
        }

};

int main() {
    cout << endl;
    cout << "Matrix m1:" << endl;
    Matrix m1({{2, 7, 3}, {5, 10, 6}, {7, 8, 10}});
    m1.print();
    cout << endl;
    
    cout << "Matrix m2:" << endl;
    Matrix m2({{4, 18, 17}, {2, 5, 4}, {20, 2, 1}});
    m2.print();
    cout << endl;
    

    Matrix sum = m1 + m2;
    cout << "Sum of matrices:\n";
    sum.print();
    cout << endl;

    Matrix product = m1 * m2;
    cout << "Product of matrices:\n";
    product.print();
    cout << endl;

    cout << "Are m1 and m2 equal? " << endl;
    (m1 == m2) ? cout << "Yes" : cout << "No" << endl << endl;

    Matrix transpose = m1.transpose();
    cout << "Transpose of m1:\n";
    transpose.print();
    cout << endl;

    Matrix sub = m1.sub_matrix(2, 2);
    cout << "Sub matrix of m1:\n";
    sub.print();
    cout << endl;

    Matrix inverse = m1.inverse();
    cout << "Inverse of m1:\n";
    cout << fixed << setprecision(2);
    inverse.print();

  return 0;
}