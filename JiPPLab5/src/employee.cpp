//#include <lab5\employee.hpp>
#include "../include/lab5/employee.hpp"

employee::employee(std::string _ID, std::string _name, std::string _surname, std::string _departmentID, std::string _position){
    this -> ID = _ID;
    this -> name = _name;
    this -> surname = _surname;
    this -> departmentID = _departmentID;
    this -> position = _position;
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
