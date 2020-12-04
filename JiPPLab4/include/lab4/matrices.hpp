#ifndef MATRICES_HPP
#define MATRICES_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <exception>

class matrixTask {
    private:
        std::vector < std::vector < double > > matrix; 
    public:
        matrixTask(int rows, int cols);
        matrixTask(int size);
        matrixTask(std::string filePath);
        ~matrixTask() = default;
        void set(int posN, int posM, double value);
        double get(int posN, int posM);
        matrixTask add(matrixTask &m2);
        matrixTask subtract(matrixTask &m2);
        matrixTask multiply(matrixTask &m2);
        int cols();
        int rows();
        void print();
        bool store(std::string fileName, std::string filePath);
};
#endif

/*      ERRORS
    *   [100] Add matrices, different size
    *   [101] Subtract matrices, different size
    *   [102] Multiply matrices, different size
    * 
    * 
*/