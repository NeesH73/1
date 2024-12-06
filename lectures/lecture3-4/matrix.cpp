#include <iostream>

using namespace std;

int** multMatrix(int** matrixA, int rowsA, int colsA, int** matrixB, int rowsB, int colsB){
    if (colsA != rowsB) {
        return nullptr;
    }
    
    int** result = new int*[rowsA];
    for (int i = 0; i < rowsA; i++) {
        result[i] = new int[colsB]{0};
    }
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

void delMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    
    cin >> rowsA >> colsA;

    int** matrixA = new int*[rowsA];
    for (int i = 0; i < rowsA; i++) {
        matrixA[i] = new int[colsA];
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> matrixA[i][j];
        }
    }
   
    cin >> rowsB >> colsB;

    int** matrixB = new int*[rowsB];
    for (int i = 0; i < rowsB; i++) {
        matrixB[i] = new int[colsB];
    }

    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> matrixB[i][j];
        }
    }

    int** result = multMatrix(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

    
    if (result == nullptr) {
        cerr << "Error: Incompatible matrix dimensions." << endl;

        
        delMatrix(matrixA, rowsA);
        delMatrix(matrixB, rowsB);

        return 1;
    }

    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    
    delMatrix(matrixA, rowsA);
    delMatrix(matrixB, rowsB);
    delMatrix(result, rowsA);

    return 0;
}