#include <lab6/matrices.hpp>

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
    std::vector <double> temp;

    file.open(filePath.c_str());
    if (file.good()){
        int rows, cols;
        file >> cols >> rows;
        int trash;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
                file >> trash; 
                temp.push_back(trash);
            }
            matrix.push_back(temp);
            temp.clear();
        }
    }
    file.close();
}

matrixTask::~matrixTask(){};

matrixTask matrixTask::add(matrixTask &m2){
    int nRows = rows();
    int nCols = cols();
    try{
        if(nRows != m2.rows() || nCols != m2.cols()){
            throw 100;
        }
        matrixTask resultMatrix = matrixTask(nRows, nCols);
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                resultMatrix.set(i, j, (get(i,j) + m2.get(i,j)));
//              (resultMatrix.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
            }
        }
        return resultMatrix;
    }
    catch (int e){
        std::cout << "Matrices add exception: " << e << "Check errors table\n";
    }
    return *this;
}

matrixTask matrixTask::subtract(matrixTask &m2){
    int nRows = rows();
    int nCols = cols();
    try{
        if(nRows != m2.rows() || nCols != m2.cols()){
            throw 101;
        }
        matrixTask resultMatrix = matrixTask(nRows, nCols);
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                resultMatrix.set(i, j, (get(i,j) - m2.get(i,j)));
//              (resultMatrix.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];
            }
        }
        return resultMatrix;
    } catch (int e){
        std::cout << "Matrices subtract exception: " << e << "Check errors table\n";
    }
    return *this;
}

matrixTask matrixTask::multiply(matrixTask &m2){
    int nRows = rows();
    int nCols = cols();
    int m2Rows = m2.rows();
    int m2Cols = m2.cols();
    double valueHolder = 0;
    try{
        if(nCols != m2Rows){
            throw 102;
        }
        else {
            matrixTask resultMatrix = matrixTask(m2Cols, nRows);
            for(int i = 0; i < nRows; i++){
                for(int j = 0; j < m2Cols; j++){
                    valueHolder = 0;
                    for(int k = 0; k < m2Rows; k++){
                        valueHolder += get(i,k) * m2.get(k,j);
                    }
                    resultMatrix.set(i, j, valueHolder);
                }     
            }
            return resultMatrix;
        }
    }
    catch(int e){
        std::cout << "Matrices multiply exception: " << e << "Check errors table\n";
    }
    return *this;
}

void matrixTask::set(int posN, int posM, double value){
    try{
        matrix.at(posN).at(posM) = value;
    }
    catch (const std::exception &error){
        std::cout << error.what() << std::endl;
    }
}

double matrixTask::get(int posN, int posM){
    double value;
    try{
        value = matrix.at(posN).at(posM);
    }
    catch (const std::exception &error){
        std::cout << error.what() << std::endl;
        return -1;
    }
    return value;
}

int matrixTask::cols(){
    return matrix[0].size();
}

int matrixTask::rows(){
    return matrix.size();
}

void matrixTask::print(){  
    for(int i = 0; i < this -> rows(); i++){
        for(int j = 0; j < this -> cols(); j++){
            std::cout << std::setw(10) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

bool matrixTask::store(std::string fileName, std::string filePath){
    std::ofstream file;
    file.open((filePath + fileName).c_str());
    if (!file.good())
        return false;

    int nRows = this -> rows();
    int nCols = this -> cols();

    file << nCols << " " << nRows;
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

matrixTask matrixTask::operator+(matrixTask &m2){
    int nRows = this -> rows();
    int nCols = this -> cols();
    try{
        if(nRows != m2.rows() || nCols != m2.cols()){
            throw 100;
        }
            matrixTask resultMatrix = matrixTask(nRows, nCols);
            for(int i = 0; i < nRows; i++){
                for(int j = 0; j < nCols; j++){
                (resultMatrix.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
                }
            }
            return resultMatrix;
    }
    catch (int e){
        std::cout << "Matrices add exception: " << e << "Check errors table\n";
    }
    return *this;
}

matrixTask matrixTask::operator-(matrixTask &m2){
int nRows = this -> rows();
    int nCols = this -> cols();
    try{
        if(nRows != m2.rows() || nCols != m2.cols()){
            throw 101;
        }
            matrixTask resultMatrix = matrixTask(nRows, nCols);
            for(int i = 0; i < nRows; i++){
                for(int j = 0; j < nCols; j++){
                    (resultMatrix.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];
                }
            }

    } catch (int e){
        std::cout << "Matrices subtract exception: " << e << "Check errors table\n";
    }
    return *this;
}

matrixTask matrixTask::operator*(matrixTask &m2){
    int nRows = this -> rows();
    int nCols = this -> cols();
    int m2Rows = m2.rows();
    int m2Cols = m2.cols();
    double valueHolder = 0;
    try{
        if(nCols != m2Rows){
            throw 102;
        }
            matrixTask resultMatrix = matrixTask(m2Cols, nRows);
            for(int i = 0; i < nRows; i++){
                for(int j = 0; j < m2Cols; j++){
                    valueHolder = 0;
                    for(int k = 0; k < m2Rows; k++){
                        valueHolder += get(i,k) * m2.get(k,j);
                    }
                    resultMatrix.set(i, j, valueHolder);
                }     
            }
            return resultMatrix;
    }
    catch(int e){
        std::cout << "Matrices multiply exception: " << e << " Check errors table\n";
    }
    return *this;
}

bool matrixTask::operator==(matrixTask &m2){
    try{
        if(this -> rows() != m2.rows() || this -> cols() != m2.cols()){
            throw 103;
        }
        for(int i = 0; i < this -> rows(); i++){
            for(int j = 0; j < this -> cols(); j++){
                if(get(i,j) != m2.get(i,j))
                    return false;
            }
        }
    }
    catch(int e){
        std::cout << "Matrices == exception: " << e << " Check errors table\n";
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, matrixTask& m2){
    out << m2.rows() << " " << m2.cols() << std::endl;
    for(int i = 0; i < m2.rows(); i++){
        for(int j = 0; j < m2.cols(); j++){
            out << m2.get(i,j) << " ";
        }
        out << std::endl;
    }
    return out;
}

std::vector<double> matrixTask::operator[](int rows){
  std::vector <double> temp;
    try{
        if(rows < 0){
            throw 104;
        }
        else if(rows > ((this -> rows()) - 1)){
            throw 104;
        }
        for(int i = 0; i < cols(); i++){
            temp.push_back(this -> get(rows, i));
        }
    }
    catch(int e){
        std::cout << "Matrices [] exception: " << e << "Check errors table\n";
    }

    return temp;
}

bool matrixTask::operator!=(matrixTask &m2){
    try{
        if(this -> rows() != m2.rows() || this -> cols() != m2.cols()){
            throw 103;
        }
        for(int i = 0; i < this -> rows(); i++){
            for(int j = 0; j < this -> cols(); j++){
                if(get(i,j) != m2.get(i,j))
                    return true;
            }
        }
    }
    catch(int e){
        std::cout << "Matrices == exception: " << e << " Check errors table\n";
    }
    return false;
}



//bool matrixTask::operator<(double valueF, double valueS){}

//bool matrixTask::operator>(double valueF, double valueS){}
