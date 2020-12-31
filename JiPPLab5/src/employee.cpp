#include <lab5\employee.hpp>
//#include "../include/lab5/employee.hpp"

employee::employee(std::string ID, std::string name, std::string surname, std::string position){
    this -> ID = ID;
    this -> name = name;
    this -> surname = surname;
    this -> position = position;
}

employee::employee(){}

std::string employee::getID(){
    return this -> ID;
}

std::string employee::getName(){
    return this -> name;
}

std::string employee::getSurname(){
    return this -> surname;
}

std::string employee::getDepartmentID(){
    return this -> departmentID;
}

std::string employee::getPosition(){
    return this -> position;
}

void employee::setDepartment(std::string departmentID){
    this -> departmentID = departmentID;
}

void employee::printEmploye(){
    std::cout << "Name: " << this -> getName() << std::endl;
    std::cout << "Surname: " << this -> getSurname() << std::endl;
    std::cout << "Position: " << this -> getSurname() << std::endl;
}

void employee::printEmployeByDepartments(){
    std::cout << "ID: " << this -> getID() << std::endl;
    std::cout << "Name: " << this -> getName() << std::endl;
    std::cout << "Surname: " << this -> getSurname() << std::endl;
    std::cout << "Position: " << this -> getSurname() << std::endl;
}
