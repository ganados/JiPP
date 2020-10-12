#include <iostream>

bool palindrom(std::string word, int wordLength){
    if(wordLength == 1) return true; //check for one letter word

//    std::cout << word << std::endl;
    for(int i = 0, j = wordLength - 1; i < wordLength / 2, j > wordLength / 2; i++, j--){
        if(isspace(word[i])) i++;
        if(isspace(word[j])) j--; //skip space

        if(word[i] != word[j]) return false; //check if first and last letter(etc) are the same
    }
    return true;
}

int main(int argc, char* argv[]){
   
    std::string word = argv[1];
    int wordLength = word.length(); //check length

//    std::cout << std::endl << argv[1] << " " << wordLength << std::endl;

    if(palindrom(word, wordLength)) std::cout << "It's a palindrome" << std::endl;
    else std::cout << "It's not a palindrome" << std::endl;
   
    return 0;
}