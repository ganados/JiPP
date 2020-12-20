#include <lab5\employee.hpp>


std::string employee::getID(){
    return this->ID;
}

std::string employee::getName(){
    return this->name;
}

std::string employee::getSurname(){
    return this->surname;
}

std::string employee::getdepartmentID(){
    return this->departmentID;
}

std::string employee::getPosition(){
    return this->position;
}

void employee::printEmployeAll(){
    std::cout << "ID: " << this->getID() << std::endl;
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Surname: " << this->getSurname() << std::endl;
    std::cout << "Position: " << this->getSurname() << std::endl;
    std::cout << "Department ID: " << this->getdepartmentID() << std::endl;
}

void employee::printEmployeByDepartments(){
    std::cout << "ID: " << this->getID() << std::endl;
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Surname: " << this->getSurname() << std::endl;
    std::cout << "Position: " << this->getSurname() << std::endl;
}