#ifndef HRMS_HPP
#define HRMS_HPP
#include <vector>
#include <list>
#include <map>
#include <lab5\employee.hpp>

class hrms{
    private:
        std::list <class employee> epmployees;
        std::map <class employee, std::string> emDepartments;
        std::map <class employee, double> emEarnings;

    public:
        hrms();
        ~hrms();
        hrms add(employee emp, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeID, double salary);
        void printSalaries();
        void printSalariesSorted();

};


#endif