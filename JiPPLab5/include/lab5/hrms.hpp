#ifndef HRMS_HPP
#define HRMS_HPP
#include <list>
#include <map>
#include <vector>
#include <algorithm>

//#include <lab5\employee.hpp>
#include "./employee.hpp"

class hrms{
    private:
        std::list <class employee> employees;
        std::map <std::string, class employee> emDepartments;
        std::map <class employee, double> emEarnings;

    public:
        hrms();
        ~hrms();
        void add(employee& emp, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeID, double salary);
        void printSalaries();
        void printSalariesSorted();

};


#endif