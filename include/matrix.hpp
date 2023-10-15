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
    // преобразования матриц, не изменяющие значения определителя: 
    // void summarize_rows();  // сложение строк
    // void multiply_rows();   // умножение строк
    // void swap_rows();   // поменять строки местами
    // void multiply_row_by_number();  // умножение строки на коэффициент

    // bool is_diagonal() {  // проверка, является ли матрица диагональной 
    //     // как это проверить?
    // }

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