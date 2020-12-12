#include <vector>
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
        int get_num_rows();
        int get_num_cols();
        vector<vector<int>> get_matrix();
};
