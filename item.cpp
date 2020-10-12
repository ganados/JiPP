#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> message {"Hello", "World", "f", "a", "c"};
    
    for (const std::string& word : message){
        std::cout << word << " ";
    }
    std::cout << std::endl;
    std::cout << "hello" << std::endl;
}