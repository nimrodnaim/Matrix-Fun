#include <iostream>
#include <vector>

using namespace std;
class Matrix {
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> matrix;
public:
    void print_matrix();
    void multiply_by_scalar(int);
    void transpose();
    static Matrix mult(Matrix, Matrix);
    static Matrix add(Matrix, Matrix);
    vector<vector<int>> get_matrix();
    int get_num_rows();
    int get_num_cols();
    Matrix(int, int);
    Matrix(int, int, vector<vector<int>>);

};
