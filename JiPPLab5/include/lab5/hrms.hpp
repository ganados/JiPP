#ifndef HRMS_HPP
#define HRMS_HPP
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <string>


#include <lab5\employee.hpp>
//#include ".\employee.hpp"

class hrms{
    private:
        std::map <std::string, class employee> employees;
        std::map <std::string, std::vector<std::string>> emDepartments;
        std::map <std::string, double> emEarnings;

    public:
        hrms();
        void add(employee& emp, std::string departmentID, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeID, double salary);
        void printSalaries();
//      hrms& operator=(const hrms&);
//      bool operator<(hrms& temp);
        bool cmp(std::pair <class employee, double>& a, std::pair <class employee, double>& b);
        void printSalariesSorted();
};


#endif