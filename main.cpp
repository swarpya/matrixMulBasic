
#include <iostream>
#include <vector>
#include <emscripten.h>

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int* multiplyMatrices(int* v1, int* v2, int aRows, int aCols, int bCols) {
        static vector<int> result(aRows * bCols);
        int sum = 0;

        for (int i = 0; i < aRows; i++) {
            for (int j = 0; j < bCols; j++) {
                sum = 0;
                for (int k = 0; k < aCols; k++) {
                    int corA = v1[i * aCols + k]; // Element from the i-th row of A
                    int corB = v2[k * bCols + j]; // Element from the j-th column of B
                    sum += corA * corB;
                }
                result[i * bCols + j] = sum; // Store the computed value in result
            }
        }
        return result.data();
    }
}

int main() {
    return 0; // Not used
}
