#include <iostream>

void changeIfSmaller(int* firstValue, int* secondValue){
    if(secondValue < firstValue){
        int trash = *firstValue;
        *firstValue = *secondValue;
        *secondValue = trash;
    }
}

void changeByRef(int &firstValue, int &secondValue){
    int trash = firstValue;
    firstValue = secondValue;
    secondValue = trash;
}

void mixedSwap(int &firstValue, int *secondValue){
    int trash = firstValue;
    firstValue = *secondValue;
    *secondValue = trash;
}

int sumAndProduct(int *product, int firstValue, int secondValue){
    *product = (firstValue * secondValue);
    return (firstValue + secondValue);
}


int main(){

    int aValue = 4;
    int bValue = 3;

    std::cout << "Start with numbers: " << std::endl;
    std::cout << aValue << " " << bValue << std::endl;

// ------------------------------First ---------------------------
    std::cout << "First task, change if second is smaller than first one" << std::endl;
    changeIfSmaller(&aValue, &bValue);
    std::cout << aValue << " " << bValue << std::endl;
   
// -------------------------------Second -------------------------
    std::cout << "Second task, change by reference" << std::endl;
    changeByRef(aValue, bValue);
    std::cout << aValue << " " << bValue << std::endl;

// -------------------------------Third --------------------------
    std::cout << "Third task, mixed change (reference and pointer)" << std::endl;
    mixedSwap(aValue, &bValue);
    std::cout << aValue << " " << bValue << std::endl;

// -------------------------------Fourth -------------------------
    std::cout << "Fourth task, mixed change (reference and pointer)" << std::endl;
    int product = 0;
    int sum = sumAndProduct(&product, aValue, bValue);
    std::cout << "Result of a + b: " << sum << std::endl << "Result of a * b: " << product << std::endl;

    return 0;
}