#include "./Headers/matrices.hpp"

int main(){
    matrixTask firstMatrix = matrixTask(5,6);
    matrixTask secondMatrix = matrixTask(6,5);
    matrixTask rectMatrix = matrixTask(5);
    matrixTask rectMatrix2 = matrixTask(5);
    srand(time(NULL));
    double temp;
// uzupelnienie macierzy
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            temp = (double)(rand() % 1000 + 1) / (i * j * 10 + 1);
            firstMatrix.set(i,j,temp);
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            temp = (double)(rand() % 100 + 1) / (i * j + 1);
            secondMatrix.set(i,j,temp);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            temp = (double)(rand() % 1000 + 1) / (i * j * 10 + 1);
            rectMatrix.set(i,j,temp);
            temp = (double)(rand() % 1000 + 1) / (i * j * 10 + 1);
            rectMatrix2.set(i,j,temp);
        }
    }
    std::cout << "---------------------------- firstMatrix 5x6 ----------------------------" <<std::endl;
    firstMatrix.print();
    std::cout << "---------------------------- secondMatrix 6x5 ----------------------------" <<std::endl;
    secondMatrix.print();
    std::cout << "---------------------------- rectMatrix 5x5 ----------------------------" <<std::endl;
    rectMatrix.print();
    std::cout << "---------------------------- rectMatrix2 5x5 ----------------------------" <<std::endl;
    rectMatrix2.print();
    std::cout << "---------------------------- ADD ----------------------------" <<std::endl;
    matrixTask resultMatrix = rectMatrix.add(rectMatrix2);
    resultMatrix.print();
    std::cout << "---------------------------- SUBTRACT ----------------------------" <<std::endl;
    matrixTask resultMatrix2 = rectMatrix.subtract(rectMatrix2);
    resultMatrix2.print();

    std::cout << "---------------------------- MULTIPLY  ----------------------------" <<std::endl;
    matrixTask resultMatrix3 = firstMatrix.multiply(secondMatrix);
    resultMatrix3.print();
    std::cout << std::endl;
    std::cout << "---------------------------- Store matrix in file  ----------------------------" <<std::endl;
    resultMatrix3.store("pliczekStore", "./");

    std::cout << "---------------------------- constructor from file ----------------------------" <<std::endl;
    matrixTask resultMatrix4 = matrixTask("./pliczek");
    resultMatrix4.print();

    return 0;
}