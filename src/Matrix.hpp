#pragma once
#include "Definitions.hpp"
#include <algorithm>
#include <cassert>
#include <vector>

NS_EA_BEGIN

template<typename T>
class Matrix {
    unsigned int n_rows, n_cols;
    std::vector<T> data;

public:
    Matrix()
        : n_rows(0)
        , n_cols(0)
        , data() {}

    Matrix(unsigned int n_rows, unsigned int n_cols)
        : n_rows(n_rows)
        , n_cols(n_cols)
        , data(n_rows * n_cols) {}

    void zeros() { std::fill(data.begin(), data.end(), T{}); }

    void zeros(unsigned int rows, unsigned int cols) {
        n_rows = rows;
        n_cols = cols;
        data.assign(rows * cols, T{});
    }

    [[nodiscard]] bool empty() { return data.empty(); }

    [[nodiscard]] unsigned int get_n_rows() const { return n_rows; }
    [[nodiscard]] unsigned int get_n_cols() const { return n_cols; }

    void clear() {
        n_rows = 0;
        n_cols = 0;
        data.clear();
    }

    void set_col(unsigned int col_idx, const std::vector<T>& col_vector) {
        assert(col_vector.size() == n_rows && "Assigned column vector size mismatch.");
        for (unsigned int i = 0; i < n_rows; i++) (*this)(i, col_idx) = col_vector[i];
    }

    void set_row(unsigned int row_idx, const std::vector<T>& row_vector) {
        assert(row_vector.size() == n_cols && "Assigned row vector size mismatch.");
        for (unsigned int i = 0; i < n_cols; i++) (*this)(row_idx, i) = row_vector[i];
    }

    void get_col(unsigned int col_idx, std::vector<T>& col_vector) const {
        col_vector.resize(n_rows);
        for (unsigned int i = 0; i < n_rows; i++) col_vector[i] = (*this)(i, col_idx);
    }

    void get_row(unsigned int row_idx, std::vector<T>& row_vector) const {
        row_vector.resize(n_cols);
        for (unsigned int i = 0; i < n_cols; i++) row_vector[i] = (*this)(row_idx, i);
    }

    void operator=(const std::vector<std::vector<T>>& A) {
        unsigned int A_rows = (unsigned int)A.size();
        unsigned int A_cols = 0;
        if (A_rows > 0) A_cols = (unsigned int)A[0].size();
        n_rows = A_rows;
        n_cols = A_cols;
        if (n_rows > 0 && n_cols > 0) {
            data.resize(n_rows * n_cols);
            for (unsigned int i = 0; i < n_rows; i++) {
                assert(A[i].size() == A_cols && "Vector of vector does not have a constant row size! A21654616");
                for (unsigned int j = 0; j < n_cols; j++) (*this)(i, j) = A[i][j];
            }
        }
        else
            data.clear();
    }

    void print() {
        for (unsigned int i = 0; i < n_rows; i++) {
            for (unsigned int j = 0; j < n_cols; j++) cout << "\t" << (*this)(i, j);

            cout << endl;
        }
        data.clear();
    }

    inline double& operator()(unsigned int row, unsigned int col) { return data[row * n_cols + col]; }
    inline double operator()(unsigned int row, unsigned int col) const { return data[row * n_cols + col]; }
};

NS_EA_END
