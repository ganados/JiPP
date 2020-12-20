#include <lab5\hrms.hpp>

//hrms add(employee emp, double salary);
//void printDepartment(std::string departmentID);
//void changeSalary(std::string employeID, double salary);
//void printSalaries();
//void printSalariesSorted();

hrms hrms::add(employee& emp, double salary){
    employees.push_back(emp);
    emDepartments.insert({emp.departmentID,emp});
    emEarnings.insert({emp, salary});
}

void hrms::printDepartment(std::string departmentID){
    std::cout << "Employees from " << departmentID << " department: " << std::endl;
/*
    for(auto element : emDepartments){
        if(element.second.getdepartmentID() == departmentID){
            element.second.printEmployeByDepartments();
        }
    }
*/
    for(auto element : emDepartments){
        if(element.first == departmentID){
            element.second.printEmployeByDepartments();
        }
    }
}