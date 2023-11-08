#include "matrix.hpp"

using namespace matrix;

int main()
{
    Matrix<int> M(3,4);
    M[3][4] = 5;
    M[1][1] = 1;
    M[1][2] = 2;
    M[1][3] = 3;
    M.print_matrix();

    M.summarize_rows(1, 3);
    M.print_matrix();

    M.multiply_row_by_number(1, 2);
    M.print_matrix();

    M.swap_rows(2, 1);
    M.print_matrix();

    M.summarize_rows(1, 3);
    M.print_matrix();

    if(!M.is_diagonal()) {
        std::cout << "Matrix is not diagonal" << std::endl;
    }

    M.summarize_rows(2, 1);
    M.print_matrix();

    Matrix<int> K(2, 2);
    K[1][1] = 1;
    K[1][2] = 0;
    K[2][1] = 0;
    K[2][2] = 1;
    K.print_matrix();

    if(K.is_diagonal()) {
        std::cout << "Matrix K is diagonal" << std::endl;
        double determinant = K.determinant_of_diagonal_matrix();
        std::cout << "Determinant of diagonal matrix: " << determinant << "\n";
    }

    Matrix<int> Diagonal_Matrix(5, 5);
    Diagonal_Matrix.create_diagonal_matrix(8, 5);
    Diagonal_Matrix.print_matrix();
    Diagonal_Matrix.summarize_rows(1, 2);
    Diagonal_Matrix.summarize_rows(4, 5);
    Diagonal_Matrix.summarize_rows(1, 2);
    Diagonal_Matrix.summarize_rows(4, 1);
    Diagonal_Matrix.summarize_rows(3, 4);
    Diagonal_Matrix.summarize_rows(5, 3);
    Diagonal_Matrix.print_matrix();
}