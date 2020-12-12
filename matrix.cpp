#include <matrix.h>

class Matrix {
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> matrix;
public:
    void print_matrix();
    void multiply_by_scalar(int);
    void transpose();
    static Matrix multiply(Matrix, Matrix);
    static Matrix add(Matrix, Matrix);
    vector<vector<int>> get_matrix();
    int get_num_rows();
    int get_num_cols();
    Matrix(int, int);
    Matrix(int, int, vector<vector<int>>);

}

Matrix::Matrix(int, int num_cols) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;

    vector<vector<int>> zero_matrix(num_rows, vector<int, num_cols>);
    this->matrix = zero_matrix;
}

Matrix::Matrix(int num_rows, int num_cols, vector<vector<int>> init_matrix) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;

    matrix = init_matrix;
}

Matrix::print_matrix() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

Matrix::multiply_by_scalar(int scalar) {
    for (int i = 0; i < this->num_rows; i++) {
        for (int j = 0; j < this->num_cols; j++) {
            this->matrix[i][j] *= scalar;
        }
    }
}

Matrix::transpose() {
    int temp = this->num_rows;
    this->num_cols = num_rows;
    this->num_rows = temp;

    vector<vector<int>> transposed_matrix(num_rows, vector<int, num_cols>);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            transposed_matrix[i][j] = this->matrix[j][i];
        }
    }

    this->matrix = transposed_matrix;
}

Matrix::get_num_rows() {
    return this->num_rows;
}

Matrix::get_num_cols() {
    return this->num_cols;
}

Matrix::get_matrix() {
    return this->matrix;
}

Matrix::add(Matrix a, Matrix b) {
    //TODO: add an exception for bad sizes
    int num_rows = a.get_num_rows();
    int num_cols = a.get_num_cols();

    vector<vector<int>> a_matrix = a.get_matrix();
    vector<vector<int>> b_matrix = b.get_matrix();
    vector<vector<int>> sum_matrix(num_rows, vector<int, num_cols>);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            sum_matrix[i][j] = a[i][j] + b[i][j];
        }
    }

    Matrix c = Matrix(num_rows, num_cols, sum_matrix);
    return c;
}

Matrix::mult(Matrix a, Matrix b) {
    //TODO: add an exception for bad sizes
    int num_rows = a.get_num_rows();
    int num_cols = b.get_num_cols();
    int value = a.get_num_cols();

    vector<vector<int>> a_matrix = a.get_matrix();
    vector<vector<int>> b_matrix = b.get_matrix();

    vector<vector<int>> mult_matrix(num_rows, vector<int, num_cols>);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            int sum = 0;
            for (int k = 0; k < value; k++) {
                sum += a_matrix[i][k] * b_matrix[k][j];
            }

            mult_matrix[i][j] = sum;
        }
    }

    Matrix c = Matrix(num_rows, num_cols, mult_matrix);
    return c;
}
