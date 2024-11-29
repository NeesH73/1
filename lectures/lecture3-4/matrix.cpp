#include <iostream>

const int mSize = 3;

int matrix_sum(int** m) // int**
{
    int sum = 0;
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}


void matrix_transpose(int** m) // int**
{
    for (int i = 0; i < mSize; i++) {
        for (int j = i + 1; j < mSize; j++) {
            std::swap(m[i][j], m[j][i]);
        }
    }
}

void matrix_print(int** m) // int**
{
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            std::cout << m[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


int main(int argc, char** argv)
{
    
    int** matrix=new int*[mSize];
    for (int i=0;i<mSize;i++){
        matrix[i]=new int[mSize];
    }
    
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            std::cin >> matrix[i][j];
        }
    }
    int matrixSum = matrix_sum(matrix);

	std::cout << "square matrix sum = " << (matrixSum*matrixSum) << std::endl;

    matrix_transpose(matrix);
    matrix_print(matrix);

	return 0;
}
