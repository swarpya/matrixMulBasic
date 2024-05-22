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
    vector<int> v1;
    vector<int> v2;

    int aRows;

cin>>aRows;

    int aCols;

cin>>aCols;
    int bCols;

cin>>bCols;

for(int i = 0; i<(aRows*aCols);i++)
{
    int j;
    cin>>j;
    v1.push_back(j);
}
for(int i = 0; i<(aRows*bCols);i++)
{
    int j;
    cin>>j;
    v2.push_back(j);
}

    vector<int> v3 = mulMatrix(v1, v2, aRows, aCols, bCols);

    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
        if ((i + 1) % bCols == 0) cout << endl; // To print in matrix form
    }
}
