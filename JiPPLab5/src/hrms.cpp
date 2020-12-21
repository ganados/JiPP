//#include <lab5\hrms.hpp>
#include "..\include\lab5\hrms.hpp"

void hrms::add(employee& emp, double salary){
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
    for(auto &element : this -> emDepartments){
        if(element.first == departmentID){
            element.second.printEmployeByDepartments();
        }
    }
}

void hrms::changeSalary(std::string employeID, double salary){
    
    for(auto &element : this -> emEarnings){
        if(element.first.ID == employeID){
            element.second = salary;
        }
    }
}

void hrms::printSalaries(){
    std::cout << "List of employees: " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(auto &element : this -> emEarnings){
        std::cout << "ID: " << element.first.ID << std::endl;
        std::cout << "Name: " << element.first.name << std::endl;
        std::cout << "Surname: " << element.first.surname << std::endl;
        std::cout << "Department: " << element.first.departmentID << std::endl;
        std::cout << "Position: " << element.first.position << std::endl;
        std::cout << "Salary: " << element.second << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl << std::endl;
    }
}

void hrms::printSalariesSorted(){
 //   sort(emEarnings.begin(), emEarnings.end());

    std::cout << "List of employees: " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(auto &element : this -> emEarnings){
        std::cout << "ID: " << element.first.ID << std::endl;
        std::cout << "Name: " << element.first.name << std::endl;
        std::cout << "Surname: " << element.first.surname << std::endl;
        std::cout << "Department: " << element.first.departmentID << std::endl;
        std::cout << "Position: " << element.first.position << std::endl;
        std::cout << "Salary: " << element.second << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl << std::endl;
    }
}