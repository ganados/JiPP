#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>

class employee {
    private: 
        std::string ID;
        std::string name;
        std::string surname;
        std::string departmentID;
        std::string position;
//        friend class hrms;
    public:
        employee(std::string ID, std::string name, std::string surname, std::string position);
        employee();
        std::string getID();
        std::string getName();
        std::string getSurname();
        std::string getDepartmentID();
        std::string getPosition();
        void setDepartment(std::string departmentID);
        void printEmploye();
        void printEmployeByDepartments();

};

#endif