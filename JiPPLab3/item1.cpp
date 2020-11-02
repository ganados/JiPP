#include <iostream>
#include <vector>
#include <iomanip>

class matrixTask {
    private:
        std::vector < std::vector < double > > matrix; 
    public:
        matrixTask(int rows, int cols);
        matrixTask(int size);
        ~matrixTask();
        void set(int posN, int posM, double value);
        double get(int posN, int posM);
        double add(matrixTask m2);
        double subtract(matrixTask m2);
        double multiply(matrixTask m2);
        int cols();
        int rows();
        void print();
        void store(std::string fileName, std::string filePath);
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

matrixTask::~matrixTask(){};

void matrixTask::set(int posN, int posM, double value){
    matrix.at(posN).at(posM) = value;
}

double matrixTask::get(int posN, int posM){
    return 1;
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

int main(){
    matrixTask firstMatrix = matrixTask(3,4);
    int size = firstMatrix.cols();
    std::cout << size;

    int maxSize = firstMatrix.rows();
    std::cout << std::endl <<maxSize;
    std::cout << std::endl;
    firstMatrix.set(0,0,1);
    firstMatrix.print();
    
    std::cout << std::endl;
    //matrixTask secondMatrix = matrixTask(4);
    //secondMatrix.print();


    return 0;
}