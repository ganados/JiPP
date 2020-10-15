#include <iostream>

void insertSort(int *&numArray, int argc){
    int j;
    int storedValue;
 
    for(int i = 1; i < argc - 1; i++){
        storedValue = numArray[i]; //safekeeping of value for exchange
        j = i - 1; //
 
        while(j >= 0 && numArray[j] > storedValue){
            numArray[j + 1] = numArray[j]; //sorting
            j -= 1;
        }
        numArray[j + 1] = storedValue; //swap values
    }
}

int main(int argc, char* argv[]){

    int *numArray = new int [argc - 1];
    for(int i = 0; i < argc - 1; i++){
        numArray[i] = atoi(argv[i + 1]);
//        std::cout << argv[i + 1] << " ";
    }
//    std::cout << std::endl;
//    std::cout << std::endl << argc << std::endl;
    insertSort(numArray, argc);

    std::cout << "out = ";
    for(int i = 0; i < argc - 1; i++){
        std::cout << numArray[i] << " ";
    }

    return 0;
}