#include <iostream>
#include <ctime>
#include <iomanip>

void displayMatrix(int matrix[2][3]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main(){
    srand(time(NULL));
    
    int matrixA[2][3];
    int matrixB[2][3];
    int matrixResult[2][3];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            matrixA[i][j] = rand() % 100 - 50;
            matrixB[i][j] = rand() % 100 - 50;
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    std::cout << "First matrix: " << std::endl;
    displayMatrix(matrixA);
    std::cout << std::endl << "Second matrix: " << std::endl;
    displayMatrix(matrixB);
    std::cout << std::endl << "Sum of matrices: " << std::endl;
    displayMatrix(matrixResult);
    
    return 0;
}