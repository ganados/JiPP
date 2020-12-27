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
        void add(employee& emp, double salary) noexcept(false);
        void printDepartment(std::string departmentID) noexcept;
        void changeSalary(std::string employeID, double salary) noexcept(false);
        void printSalaries() noexcept;
        bool cmp(std::pair <class employee, double>& a, std::pair <class employee, double>& b) noexcept;
        void printSalariesSorted() noexcept;
};


#endif