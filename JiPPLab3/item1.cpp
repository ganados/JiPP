#include <iostream>
#include <vector>

class matrixTask {
    private:
        std::vector < std::vector < double > > matrix; 
    public:
        matrixTask(int rows, int cols);
        matrixTask(int size);
        ~matrixTask();
        void set(int posN, int posM, int value);
        double get(int posN, int posM);
        double add(matrixTask m2);
        double subtract(matrixTask m2);
        double multiply(matrixTask m2);
        int cols();
        int rows();
        void print(matrixTask matrix);
        void store(std::string fileName, std::string filePath);
        matrixTask(std::string filePath);
};

matrixTask::matrixTask(int rows, int cols){
    matrix.reserve(rows);
    for(int i = 0; i < rows; i++)
        matrix[i].reserve(cols);
}
matrixTask::matrixTask(int size){
    matrix.reserve(size);
    for(int i = 0; i < size; i++)
        matrix[i].reserve(size);
}

matrixTask::~matrixTask(){};

void matrixTask::set(int posN, int posM, int value){

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

int main(){
    matrixTask firstMatrix = matrixTask(3,4);
    int size = firstMatrix.cols();
    std::cout << size;
    int maxSize = firstMatrix.rows();
    std::cout << std::endl <<maxSize;

    return 0;
}