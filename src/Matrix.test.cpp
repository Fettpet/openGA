#include <Matrix.hpp>
#include <gtest/gtest.h>

struct MatrixTest : ::testing::Test {

    void SetUp() override {
        doubleMatrix = EA::Matrix<double>(nbRows, nbCols);
        intMatrix = EA::Matrix<int>(nbRows, nbCols);
    }

    const int nbRows = 42;
    const int nbCols = 13;

    EA::Matrix<double> doubleMatrix;
    EA::Matrix<int> intMatrix;
};

TEST_F(MatrixTest, get_n_rows) { EXPECT_EQ(intMatrix.get_n_rows(), nbRows); }
TEST_F(MatrixTest, get_n_cols) { EXPECT_EQ(intMatrix.get_n_cols(), nbCols); }

TEST_F(MatrixTest, empty) { EXPECT_FALSE(intMatrix.empty()); }

TEST_F(MatrixTest, clear) {
    intMatrix.clear();
    EXPECT_TRUE(intMatrix.empty());
    EXPECT_EQ(intMatrix.get_n_rows(), 0);
    EXPECT_EQ(intMatrix.get_n_cols(), 0);
}

TEST_F(MatrixTest, zeros) {
    intMatrix.zeros();
    EXPECT_EQ(intMatrix.get_n_rows(), nbRows);
    EXPECT_EQ(intMatrix.get_n_cols(), nbCols);

    for (auto row = 0; row < nbRows; ++row) {
        for (auto col = 0; col < nbCols; ++col) {
            EXPECT_EQ(intMatrix(row, col), 0);
        }
    }
}

TEST_F(MatrixTest, zerosArg) {
    const int nbRows = 5;
    const int nbCols = 6;
    intMatrix.zeros(nbRows, nbCols);
    EXPECT_EQ(intMatrix.get_n_rows(), nbRows);
    EXPECT_EQ(intMatrix.get_n_cols(), nbCols);

    for (auto row = 0; row < nbRows; ++row) {
        for (auto col = 0; col < nbCols; ++col) {
            EXPECT_EQ(intMatrix(row, col), 0);
        }
    }
}

TEST_F(MatrixTest, writeAndRead) {
    intMatrix.zeros();
    intMatrix(4, 5) = 5;
    EXPECT_EQ(intMatrix(4, 5), 5);
}

TEST_F(MatrixTest, readFromVector) {
    std::vector<std::vector<int>> test{};
    test.resize(3, std::vector<int>{1, 2, 3, 4});
    intMatrix = test;
    EXPECT_EQ(intMatrix.get_n_cols(), 4);
    EXPECT_EQ(intMatrix.get_n_rows(), 3);
    EXPECT_EQ(intMatrix(0, 0), 1);
}

TEST_F(MatrixTest, readFromVectorError) {
    std::vector<std::vector<int>> test{};
    test.resize(3, std::vector<int>{});
    intMatrix = test;
    EXPECT_EQ(intMatrix.get_n_cols(), 0);
    EXPECT_EQ(intMatrix.get_n_rows(), 0);
}

TEST_F(MatrixTest, getAndSetRow) {
    std::vector<int> testRow(nbCols);
    int value = 0;
    std::generate(testRow.begin(), testRow.end(), [&value]() { return ++value; });
    intMatrix.set_row(2, testRow);
    std::vector<int> result;
    intMatrix.get_row(2, result);
    EXPECT_EQ(result, testRow);
}

TEST_F(MatrixTest, getAndSetCol) {
    std::vector<int> testCol(nbRows);
    int value = 0;
    std::generate(testCol.begin(), testCol.end(), [&value]() { return ++value; });
    intMatrix.set_col(2, testCol);
    std::vector<int> result;
    intMatrix.get_col(2, result);
    EXPECT_EQ(result, testCol);
}

TEST_F(MatrixTest, OutOfBoundRow) {
#ifdef NDEBUG
    EXPECT_THROW({ (void)intMatrix(nbRows, 0); }, std::out_of_range);
#endif
}

TEST_F(MatrixTest, OutOfBoundCol) {
#ifdef NDEBUG
    EXPECT_THROW({ (void)intMatrix(0, nbCols); }, std::out_of_range);
#endif
}
