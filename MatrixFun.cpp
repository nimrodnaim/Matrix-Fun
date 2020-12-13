// MatrixFun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "matrix.h"
using namespace std;


int main() {
    vector<vector<int>> init_matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    Matrix a = Matrix(3 , 3, init_matrix);
    Matrix b (3, 4);
    
    b.print_matrix();
    
    b.transpose();
    b.print_matrix();
}