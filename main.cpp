#include<iostream>
#include<vector>
using namespace std;

vector<int> mulMatrix(vector<int> &v1, vector<int> &v2, int aRows, int aCols, int bCols) {
    vector<int> v3;
    int sum = 0;

    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            sum = 0;
            for (int k = 0; k < aCols; k++) {
                int corA = v1[i * aCols + k]; // Element from the i-th row of A
                int corB = v2[k * bCols + j]; // Element from the j-th column of B
                sum += corA * corB;
            }
            v3.push_back(sum); // Store the computed value in v3
        }
    }
    return v3;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6}; // 3x3 matrix
    vector<int> v2 = {1, 2, 3, 4, 5, 6}; // 3x2 matrix

    int aRows = 3; // Number of rows in A
    int aCols = 3; // Number of columns in A
    int bCols = 2; // Number of columns in B

    vector<int> v3 = mulMatrix(v1, v2, aRows, aCols, bCols);

    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
        if ((i + 1) % bCols == 0) cout << endl; // To print in matrix form
    }
}
