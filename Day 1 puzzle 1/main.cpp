#include <iostream>
#include <fstream>
#include <string>

int main(){
    int biggestElfLoad = 0;
    int currentElfLoad = 0;
    std::string calories;
    std::fstream input("input/input");

    if(!input.good())
        std::cout << "huh?\n";

    while( std::getline(input,calories) ){
        if( calories == "" ){
            if( currentElfLoad > biggestElfLoad ){
                biggestElfLoad = currentElfLoad;
            }

            std::cout << biggestElfLoad << "\n";
            currentElfLoad = 0;
            continue;
        }
        currentElfLoad += std::stoi(calories);
    }

    std::cout << biggestElfLoad << "\n";
}
