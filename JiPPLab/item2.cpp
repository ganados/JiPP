#include <iostream>

int main(){
    
    double height;
    double weight;
    std::cout << "Enter your weight [kg] and height [m]: ";
    std::cin >> weight >> height;

    double bmi = weight / (height * height);
    std::cout << "Your BMI: " << bmi << std::endl;
   
    if(bmi < 16) std::cout << "starvation" << std::endl;
    else if(bmi > 15.99 && bmi < 17) std::cout << "emaciation" << std::endl;
    else if(bmi > 16.99 && bmi < 18.50) std::cout << "underweight" << std::endl;
    else if(bmi > 18.49 && bmi < 25) std::cout << "correct value" << std::endl;
    else if(bmi > 24.99 && bmi < 30) std::cout << "Obesity I degree" << std::endl;
    else if(bmi > 29.99 && bmi < 40) std::cout << "2nd degree of obesity" << std::endl;
    else std::cout << "extreme obesity" << std::endl;

    return 0;
}