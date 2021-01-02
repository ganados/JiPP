#include <lab5\hrms.hpp>
#include <lab5\exceptions.hpp>
//#include "..\include\lab5\hrms.hpp"

int main(){

    employee a("A1","aa","bb","x");
    employee b("A2","cc","dd","x");
    employee c("A3","dd","ee","y");
    employee d("B1","ff","gg","x");
    employee e("B2","hh","ii","z");
    employee f("C1","jj","kk","xy");
    employee g("C2","ll","mm","z");
    employee h("D1","nn","oo","zy");
    employee i("D2","uu","pp","yz");
    employee j("D3","rr","ss","x");

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