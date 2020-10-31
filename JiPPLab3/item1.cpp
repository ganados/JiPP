#include <iostream>

class matrixTask {
    private:
        double** matrix = nullptr;
    public:
        matrixTask(int cols, int rows);
        ~matrixTask();
        void printMatrix();
};

matrixTask::matrixTask(int cols, int rows){
    matrix = new double *[rows];
    for(int i = 0; i < cols; i++)
        matrix[i] = new double;
}
matrixTask::~matrixTask(){};