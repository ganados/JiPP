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

void swapValues(int* firstValue, int* secondValue){
        int trash = *firstValue;
        *firstValue = *secondValue;
        *secondValue = trash;
}

void overloadedSwapValues(int &firstValue, int &secondValue){
    int trash;
    trash = firstValue;
    firstValue = secondValue;
    secondValue = trash;
}

void overloadedSwapValues(float &firstValue, float &secondValue){
    float trash;
    trash = firstValue;
    firstValue = secondValue;
    secondValue = trash;
}


int main(){

    int aValue = 4;
    int bValue = 3;

    std::cout << "Start with numbers: " << std::endl;
    std::cout << aValue << " " << bValue << std::endl << std::endl;

// ------------------------------First ---------------------------
    std::cout << "First task, change if second is smaller than first one" << std::endl;
    changeIfSmaller(&aValue, &bValue);
    std::cout << aValue << " " << bValue << std::endl << std::endl;
   
// -------------------------------Second -------------------------
    std::cout << "Second task, change by reference" << std::endl;
    changeByRef(aValue, bValue);
    std::cout << aValue << " " << bValue << std::endl << std::endl;

// -------------------------------Third --------------------------
    std::cout << "Third task, mixed change (reference and pointer)" << std::endl;
    mixedSwap(aValue, &bValue);
    std::cout << aValue << " " << bValue << std::endl << std::endl;

// -------------------------------Fourth -------------------------
    std::cout << "Fourth task, mixed change (reference and pointer)" << std::endl;
    int product = 0;
    int sum = sumAndProduct(&product, aValue, bValue);
    std::cout << "Result of a + b: " << sum << std::endl << "Result of a * b: " << product << std::endl << std::endl;

// -------------------------------Fifth --------------------------
    std::cout << "Fifth task, swap 2 values" << std::endl;
    swapValues(&aValue, &bValue);
    std::cout << aValue << " " << bValue << std::endl << std::endl;

// -------------------------------Sixth --------------------------
    std::cout << "Sixth task, swap 2 values with overloading" << std::endl;
    overloadedSwapValues(aValue, bValue);
    std::cout << aValue << " " << bValue << std::endl << std::endl;

    return 0;
}