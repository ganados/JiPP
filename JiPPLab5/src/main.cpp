#include <lab5\hrms.hpp>
#include <lab5\exceptions.hpp>

//#include "..\include\lab5\hrms.hpp"

int main(){
    static int key = 0;
    employee a(std::to_string(++key),"aa","bb","x");
    employee b(std::to_string(++key),"cc","dd","x");
    employee c(std::to_string(++key),"dd","ee","y");
    employee d(std::to_string(++key),"ff","gg","x");
    employee e(std::to_string(++key),"hh","ii","z");
    employee f(std::to_string(++key),"jj","kk","xy");
    employee g(std::to_string(++key),"ll","mm","z");
    employee h(std::to_string(++key),"nn","oo","zy");
    employee i(std::to_string(++key),"uu","pp","yz");
    employee j(std::to_string(++key),"rr","ss","x");

    hrms fact;
   
    try{
        fact.add(a,"dep1",2500.0);
        fact.add(b,"dep1",2600.0);
        fact.add(c,"dep1",2800.0);
        fact.add(d,"dep2",3000.0);
        fact.add(e,"dep2",3500.0);
        fact.add(f,"dep3",4500.0);
        fact.add(g,"dep3",5500.0);
        fact.add(h,"dep4",2500.0);
        fact.add(i,"dep4",3500.0);
        fact.add(j,"dep4",5500.0);
    }
    catch(std::exception &error){
        std::cout << error.what() << std::endl;
    }

    try{
//        fact.printDepartment("dep5");
        fact.printDepartment("dep1");
    }
    catch(std::exception &error){
        std::cout << error.what() << std::endl;
    }

//    std::cout << std::endl << std::endl;
    
    try{
        fact.changeSalary("A1", 4000.0);
    }
    catch(std::exception &error){
        std::cout << error.what() << std::endl;
    }

    std::cout << std::endl;
    
    fact.printSalaries();

    std::cout << std::endl << std::endl;
    
    fact.printSalariesSorted();

    return 0;
}