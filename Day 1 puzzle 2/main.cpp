#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main(){
    int currentElfLoad = 0;
    int cumulativeElfLoads = 0;
    std::list<int> elfLoads;
    std::string calories;
    std::fstream input("input/input");

    if(!input.good())
        std::cout << "huh?\n";

    while( std::getline(input,calories) ){
        if( calories == "" ){
            elfLoads.push_back(currentElfLoad);
            currentElfLoad = 0;
            continue;
        }
        currentElfLoad += std::stoi(calories);
    }

    elfLoads.sort();
    for(int i = 0; i < 3 && elfLoads.size()>0; i++){
        cumulativeElfLoads += elfLoads.back();
        elfLoads.pop_back();
    }

    std::cout << cumulativeElfLoads << "\n";
}
