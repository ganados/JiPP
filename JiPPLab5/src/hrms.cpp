#include <lab5\hrms.hpp>
#include <lab5\exceptions.hpp>
//#include "..\include\lab5\hrms.hpp"

hrms::hrms(){}

void hrms::add(employee& emp, std::string departmentID, double salary) {
//    static int temp;
//    if(employees.find(emp.getID()) != employees.end() && temp !=0){
    if(employees.find(emp.getID()) != employees.end() && !employees.empty()){    
        throw duplicateID();
    }
//    temp++;

    emp.setDepartment(departmentID);
    this -> employees[emp.getID()] = emp;
    this -> emDepartments[departmentID].push_back(emp.getID());
    this -> emEarnings[emp.getID()] = salary;
}

void hrms::printDepartment(std::string departmentID){
    if(emDepartments.find(departmentID) == emDepartments.end()){
        throw noDepartment();
    }

    std::cout << "Employees from " << departmentID << " department: " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(auto &element : emDepartments[departmentID]){
        std::cout << "ID: " <<element << std::endl;
        employees.at(element).printEmploye();
        std::cout << "-----------------------------------------------------" << std::endl << std::endl;
    }
}

void hrms::changeSalary(std::string employeID, double salary){
    if(emEarnings.find(employeID) == emEarnings.end()){
        throw noWorker();
    }

    this -> emEarnings[employeID] = salary;
}

void hrms::printSalaries(){
    std::cout << "List of employees: " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(auto &element : this -> emEarnings){
        std::cout << "ID: " << element.first << std::endl;
        std::cout << "Name: " << employees.at(element.first).getName() << std::endl;
        std::cout << "Surname: " << employees.at(element.first).getSurname() << std::endl;
        std::cout << "Department: " << employees.at(element.first).getDepartmentID() << std::endl;
        std::cout << "Position: " << employees.at(element.first).getPosition() << std::endl;
        std::cout << "Salary: " << element.second << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl << std::endl;
    }
}

void hrms::printSalariesSorted(){

    std::vector < std::pair <employee, double>> sorted;
    for(auto &element : employees){
        sorted.push_back(std::make_pair(element.second, this -> emEarnings[element.second.getID()]));
    }

    std::sort(sorted.begin(), sorted.end(), [](std::pair <employee, double>& a, std::pair <employee, double>& b){
        return (a.second > b.second);
    });

    std::cout << "List of employees sorted by salary: " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(auto &element : sorted){
        std::cout << "ID: " << element.first.getID() << std::endl;
        std::cout << "Name: " << element.first.getName() << std::endl;
        std::cout << "Surname: " << element.first.getSurname() << std::endl;
        std::cout << "Department: " << element.first.getDepartmentID() << std::endl;
        std::cout << "Position: " << element.first.getPosition() << std::endl;
        std::cout << "Salary: " << element.second << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl << std::endl;
    }
}
