#include <random> 
#include <iostream>

int main(){
    std::random_device generator; 
    std::mt19937 gen(generator());
    std::uniform_int_distribution<> dist(1,100);
    
    int randnum {};
    char option {};


    std::cout << "Welcome to Jt's Guessing Game!!!\n"; 
    std::cout << "You'll have to guess a number between 1 and 100\n";
    std::cout << "You'll have 9 attempts to guess the correct number c: \n";


    while (1) {
        std::cout << "Type (s) to start or (q) to quit in small letters \n";
        std::cin >> option; 
        if (option == 's'){
            randnum = dist(gen);
            int guess {};
            for (int i = 1; i <= 9; i++){
                std::cout << "Tries Remaining: "<< 10 - i << "\n" << "Enter the Guess: \n";
                std::cin >> guess;
                if (guess == randnum) {
                    std::cout << "Correct Guess!!!!!!!!!\n";
                    break;
                }
                else if (i == 9 && guess != randnum){
                    std::cout << "Game Over!!!!\n";
                    std::cout << "The number was " << randnum << "\n";
                }
                else{
                    std::cout << "Incorrect Guess :(\n\n";
                    continue;
                }
            }
        }
        else if (option == 'q'){
            break;
        }
        else{
            std::cout << "Invalid input! Try again c: \n";
            continue; 
        }
    }
    return 0;
}
