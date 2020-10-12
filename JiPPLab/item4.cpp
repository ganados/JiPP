#include <iostream>
#include <math.h>

int numDivisorsSum(int numberX){

    int divisorsSum = 0;

    for(int i = 1; i < sqrt(numberX); i++){ // 1 ... sqrt(x)
        if(numberX % i == 0) {
            divisorsSum += i;

            if(numberX / i != i && numberX / i != numberX){
                divisorsSum += numberX / i; // sqrt(x) ... x
            }
        }
    }
    return divisorsSum;
}

int main(){

    int numberA;
    int numberB;
    std::cout << "Enter numbers: ";
    std::cin >> numberA >> numberB;

    std::cout << "Divisors sum: " << numDivisorsSum(numberA) << "  " << numDivisorsSum(numberB) << std::endl;

    if(numDivisorsSum(numberA) == numberB + 1 && numDivisorsSum(numberB) == numberA + 1) //checking the conditions
        std::cout << "These numbers are associated" << std::endl;
    else
        std::cout << "These numbers are not associated" << std::endl;

    return 0;
}