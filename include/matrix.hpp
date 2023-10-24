// Matrix.hpp

#pragma once

#include <iostream>
#include <vector>
#include <memory>

namespace matrix {

template <typename M> 
class Matrix {
 private:
    struct ProxyRow {
        std::shared_ptr<M[]> row; // умный указатель на массив объектов типа М

        ProxyRow(int n) { // конструкторуирует структуру ProxyRow
            row = std::make_shared<M[]> (n); // row указывает на массив размера n типа М
        }
        
        ProxyRow(const ProxyRow &rhs) : row(rhs.row) {} // конструктор копирования

        ProxyRow& operator=(const ProxyRow& rhs) {
            if (this != &rhs) {
                row = rhs.row;
            }
            return *this;
        } // операция присваивания

        ProxyRow(ProxyRow &&rhs) noexcept : row(rhs.row) {
            rhs.row = nullptr;
        } // конструктор перемещения

        ProxyRow& operator=(ProxyRow &&rhs) noexcept {
            if (this != &rhs) {
                row = std::move(rhs.row);
                rhs.row = nullptr;
            }
            return *this;
        } // оператор перемещения

        const M& operator[](int n) const {return row[n]; }
        M& operator[](int n) {return row[n]; }
    };

    int rows;
    int cols;
    std::shared_ptr<ProxyRow[]> data; // умный указатель на массив объектов типа ProxyRow

 public:
    ProxyRow operator[](int n) {
        return data[n - 1];
    }

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = std::make_shared<ProxyRow[]> (rows);
        for (int i = 0; i < rows; ++i) {
            std::cout << i << std::endl;
            data[i] = ProxyRow(cols);
        }
    }

    // Matrix(const Matrix &rhs) : rows(rhs.rows), cols(rhs.cols) {
    //     data = std::make_shared<M[]>(rows);

    //     for (int i = 0; i < rows; i++) {
    //         data[i] = std::make_shared<M>(cols);

    //         for (int j = 0; j < cols; j++) {
    //             data[i][j] = rhs.data[i][j];
    //         }
    //     }
    // } // копирующий конструктор

    // Matrix(Matrix&& rhs) : rows(rhs.rows), cols(rhs.cols), data(rhs.data) {
    //     rhs.data = nullptr;
    // } // перемещающий конструктор

    // static Matrix eye(int n) {
    //     Matrix eye = Matrix(n, n);
    //     // заполнить единичками по диагонали
    //     //
    //     return eye;
    // } // конструктор для создания единичной матрицы (она всегда квадратная)



    // void print_matrix() {
    //     std::cout << "Matrix has rows = " << rows << ", cols = " << cols << std::endl;
    //     for(int i = 0; i < rows; i++) {
    //         for(int j = 0; j < cols; j++) {
    //             std::cout << data[i][j] << " ";
    //         }
    //         std::cout << "\n";
    //     }
    // }

    // void summarize_rows(int row_number_the_first_term, int row_number_the_second_term) {
    //     for(int j = 1; j <= cols; j++) { 
    //         data[row_number_the_first_term - 1][j] += data[row_number_the_second_term - 1][j];
    //     }
    // }  // сложение строк

    // void multiply_row_by_number(int row_number, M multiplier) {
    //     for(int j = 1; j <= cols; j++) { 
    //         data[row_number - 1][j] *= multiplier;
    //     }
    // } // умножение строки на число

    // void swap_rows(int first_row_number, int second_row_number) {
    //     auto tmp = data[first_row_number - 1];
    //     data[first_row_number - 1] = data[second_row_number - 1];
    //     data[second_row_number - 1] = tmp;
    // } // поменять строки местами

    // bool is_diagonal() {
    //     if(rows == cols) {
    //         for(int i = 0; i < rows; i++) {
    //             if((data[i][i + 1] != 0) && (data[i][i] == 0))
    //             {
                    
    //                 return true;
    //             }
    //             else {
                    
    //                 return false;
    //             }
    //         }
    //     }
    //     return false;
    // } // проверка, является ли матрица диагональной 

    // M determinant_of_diagonal_matrix()  { // подсчет определителя диагональной матрицы
    //     if(is_diagonal()) {
    //         for()
    //         auto determinant = 
    //         return determininant;
    //     }
    // }

    // M create_diagonal_matrix()  {  // создание диагональной матрицы
    //     return determinant_of_diagonal_matrix();
    // }

    // M gaussian_algorithm() {
    //     if(!is_diagonal()) {
    //         find_max_elem_in_first_column();
    //         swap_rows();

    //     }
    //     else {
    //         return determinant_of_diagonal_matrix();
    //     }
    // }
    
    

    // Алгоритм Гаусса с выбором главного элемента:
    // *********************************************
    // 1. Производится поиск максимального по модулю элемента в первом столбце матрицы. 
    //      Если такой элемент найден в строке i, то i-ю строку матрицы меняют местами с первой строкой.
    // 2. Далее производится вычитание из всех строк, кроме первой, первой строки, умноженной на коэффициент,
    //      равный отношению i-го элемента в строке к первому элементу в первой строке.
    // 3. Аналогично продолжается процесс для оставшихся столбцов матрицы до тех пор, пока матрица не будет приведена к треугольному виду.

    // если в процессе приведения матрицы к треугольному виду было выполнено четное число перестановок строк,
    //  то знак детерминанта не меняется, а если нечетное - меняется на противоположный


};

} // namespace matrix