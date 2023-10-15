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
}