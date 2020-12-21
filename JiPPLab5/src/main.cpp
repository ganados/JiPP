#include <iostream>

//#include <lab5\employee.hpp>
#include "..\include\lab5\employee.hpp"
//#include <lab5\hrms.hpp>
#include "..\include\lab5\hrms.hpp"

int main(){

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

    hrms fact;

    fact.add(a,2500.0);
    fact.add(b,2600.0);
    fact.add(c,2800.0);
    fact.add(d,3000.0);
    fact.add(e,3500.0);
    fact.add(f,4500.0);
    fact.add(g,5500.0);
    fact.add(h,2500.0);
    fact.add(i,3500.0);
    fact.add(j,5500.0);

    fact.printDepartment("dep1");
    std::cout << std::endl << std::endl;
    fact.printSalaries();
    std::cout << std::endl << std::endl;
    fact.printSalariesSorted();

    return 0;
}