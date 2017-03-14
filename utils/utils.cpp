//
// Created by JinTian on 14/03/2017.
//
#include <iostream>

using namespace std;

void print_matrix(double m[100][100], int rows, int columns){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

