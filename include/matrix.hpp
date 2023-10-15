#include <iostream>
#include <vector>

namespace matrix {

template <typename M> 
class Matrix {
 private:
    int **data;
    int rows;
    int cols;

 public:
    Matrix(int rows, int cols) { 
        this->rows = rows;
        this->cols = cols;
        data = new M*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new M[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    } // деструктор

    Matrix(const Matrix &rhs) : rows(rhs.rows), cols(rhs.cols) {
        data = new M*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new M[cols];

            for (int j = 0; j < cols; j++) {
                data[i][j] = rhs.data[i][j];
            }
        }
    } // копирующий конструктор

    Matrix(Matrix&& rhs) : rows(rhs.rows), cols(rhs.cols), data(rhs.data) {
        rhs.data = nullptr;
    } // перемещающий конструктор

    Matrix& operator=(const Matrix& rhs) {
        if (this != &rhs) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = rhs.rows;
            cols = rhs.cols;
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = rhs.data[i][j];
                }
            }
        }
        return *this;
    } // оператор присваивания
    
    Matrix& operator=(Matrix&& rhs) {
        if (this != &rhs) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = rhs.rows;
            cols = rhs.cols;
            data = rhs.data;
            rhs.data = nullptr;
        }
        return *this;
    } // оператор перемещения

    // static Matrix eye(int n){
    //     this->rows = n;
    //     this->cols = n;
    // }; // конструктор для создания единичной матрицы (она всегда квадратная)

    M* operator[](int row) {
        return data[row - 1];
    }

    void print_matrix() {
        std::cout << "Matrix has rows = " << rows << ", cols = " << cols << std::endl;
        for(int i = 0; i < rows; i++) {
            for(int j = 1; j <= cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void summarize_rows(int row_number_the_first_term, int row_number_the_second_term) {
        for(int j = 1; j <= cols; j++) { 
            data[row_number_the_first_term - 1][j] += data[row_number_the_second_term - 1][j];
        }
    }  // сложение строк

    void multiply_row_by_number(int row_number, M multiplier) {
        for(int j = 1; j <= cols; j++) { 
            data[row_number - 1][j] *= multiplier;
        }
    } // умножение строки на число

    void swap_rows(int first_row_number, int second_row_number) {
        auto tmp = data[first_row_number - 1];
        data[first_row_number - 1] = data[second_row_number - 1];
        data[second_row_number - 1] = tmp;
    } // поменять строки местами

    bool is_diagonal() {
        if(rows == cols) {
            for(int i = 0; i < rows; i++) {
                for(int j = 1; j <= cols; j++) {
                    if((data[i][i + 1] != 0) && (data[i][i] == 0))
                    {
                        
                        return true;
                    }
                    else {
                        
                        return false;
                    }
                }
            }
        }
        return false;
    } // проверка, является ли матрица диагональной 

    // M determinant_of_diagonal_matrix()  { // подсчет определителя диагональной матрицы
    //     if(is_diagonal()) {
    //         // логика перемножения всех диагональных элементов
    //         // return determininant;
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