#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

class matrixTask {
    private:
        std::vector < std::vector < double > > matrix; 
    public:
        matrixTask(int rows, int cols);
        matrixTask(int size);
        ~matrixTask();
        void set(int posN, int posM, double value);
        double get(int posN, int posM);
        matrixTask add(matrixTask m2);
        matrixTask subtract(matrixTask m2);
        matrixTask multiply(matrixTask m2);
        int cols();
        int rows();
        void print();
        bool store(std::string fileName, std::string filePath);
        matrixTask(std::string filePath);
};

matrixTask::matrixTask(int rows, int cols){
    std::vector <double> temp;
    for(int j = 0; j < cols; j++){
            temp.push_back(0);
        }
    for(int i = 0; i < rows; i++){
        matrix.push_back(temp);
    }
}
matrixTask::matrixTask(int size){
    std::vector <double> temp;
    for(int j = 0; j < size; j++){
            temp.push_back(0);
        }
    for(int i = 0; i < size; i++){
        matrix.push_back(temp);
    }
}
matrixTask::matrixTask(std::string filePath){
    std::ifstream file;
    file.open(filePath.c_str());
    if (file.good()){
        int rows, cols;
        file >> rows >> cols;
        int trash;
        std::vector <double> temp;
        for(int j = 0; j < cols; j++){
                file >> trash;
                temp.push_back(trash);
            }
        for(int i = 0; i < rows; i++){
            matrix.push_back(temp);
      }
    }
    file.close();
}

matrixTask::~matrixTask(){};

matrixTask matrixTask::add(matrixTask m2){
    int nRows = rows();
    int nCols = cols();
    matrixTask resultMatrix = matrixTask(nRows, nCols);
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            (resultMatrix.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
        }
    }
    return resultMatrix;    
}

matrixTask matrixTask::subtract(matrixTask m2){
    int nRows = rows();
    int nCols = cols();
    matrixTask resultMatrix = matrixTask(nRows, nCols);
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            (resultMatrix.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];
        }
    }
    return resultMatrix;    
}

matrixTask matrixTask::multiply(matrixTask m2){
    int nRows = rows();
    int nCols = cols();
    int m2Rows = m2.rows();
    int m2Cols = m2.cols();
    int valueHolder = 0;
    matrixTask resultMatrix = matrixTask(m2Cols, nRows);
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < m2Cols; j++){
            valueHolder = 0;
            for(int k = 0; k < m2Rows; k++){
                valueHolder += matrix[i][k] * (m2.matrix)[k][j];
            }
            (resultMatrix.matrix)[i][j] = valueHolder;
        }     
    }
    return resultMatrix;  
}

void matrixTask::set(int posN, int posM, double value){
    matrix.at(posN).at(posM) = value;
}

double matrixTask::get(int posN, int posM){
    return matrix.at(posN).at(posM);
}

int matrixTask::cols(){
    return matrix[0].size();
}

int matrixTask::rows(){
    return matrix.size();
}

void matrixTask::print(){
    
    for(int i = 0; i < rows(); i++){
        for(int j = 0; j < cols(); j++){
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

bool matrixTask::store(std::string fileName, std::string filePath)
{
    std::ofstream file;
    file.open(fileName.c_str());
    if (!file.good())
        return false;

    int nRows = rows();
    int nCols = cols();

    file << nRows << " " << nCols;
    file << std::endl;
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            file << matrix[i][j] << " ";
        }
        file << std::endl;
    }
/*
    std::string wiersz;
    while (std::getline(file, wiersz)) {
    }
*/
    file.close();
    return true;
}

int main(){
    matrixTask firstMatrix = matrixTask(2,2);
    matrixTask secondMatrix = matrixTask(2,2);
    firstMatrix.set(0,0,1);
    firstMatrix.set(0,1,1);
    firstMatrix.set(1,0,1);
    firstMatrix.set(1,1,1);
    firstMatrix.print();

    std::cout << std::endl;

    secondMatrix.set(0,0,2);
    secondMatrix.set(0,1,2);
    secondMatrix.set(1,0,2);
    secondMatrix.set(1,1,2);
    secondMatrix.print();

    std::cout << std::endl;

    matrixTask resultMatrix = firstMatrix.add(secondMatrix);
    resultMatrix.print();

    std::cout << std::endl;

    matrixTask resultMatrix2 = firstMatrix.subtract(secondMatrix);
    resultMatrix2.print();

    std::cout << std::endl;

    matrixTask resultMatrix3 = firstMatrix.multiply(secondMatrix);
    resultMatrix3.print();
    std::cout << std::endl;
    //resultMatrix3.store("pliczek", "./");

    matrixTask resultMatrix4 = matrixTask("./pliczek");
    resultMatrix4.print();

    return 0;
}