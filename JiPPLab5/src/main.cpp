//#include <iostream>

//#include <lab5\employee.hpp>
//#include "..\include\lab5\employee.hpp"
#include <lab5\hrms.hpp>
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
/* 
    employee a("A1","aa","bb","dep1","x");
    employee b("A2","cc","dd","dep1","x");
    employee c("A3","dd","ee","dep1","y");
    employee d("B1","ff","gg","dep2","x");
    employee e("B2","hh","ii","dep2","z");
    employee f("C1","jj","kk","dep3","xy");
    employee g("C2","ll","mm","dep3","z");
    employee h("D1","nn","oo","dep4","zy");
    employee i("D2","uu","pp","dep4","yz");
    employee j("D3","rr","ss","dep4","x");
*/

    hrms fact;
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

    fact.printDepartment("dep1");
    std::cout << std::endl << std::endl;
    fact.printSalaries();
    std::cout << std::endl << std::endl;
    fact.printSalariesSorted();

    return 0;
}