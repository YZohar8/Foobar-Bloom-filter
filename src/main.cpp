#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

#include "bloomFilter.h"
#include "HashFunction.h"

bool isValidInput (std::string& input) {
    for (char c : input)
    {
        if (!std::isdigit(c) && !std::isspace(s)){
            return false;
        }
    }
    return true;
    
}

int main() {

    std::string line;
    size_t bloom_size;
    std::vector<size_t> rounds_hash;
    std::vector<std::function<size_t(const std::string&)>> hash_functions;

    std::cerr << "enter input\n";

    // recive that first line
    do
    {
        std::getline(std::cin, line);
    } while (isValidInput(line));
    
    std::istringstream iss(line);

    iss >> bloom_size;
    int rounds;
    int count = 0;
    while (iss >> rounds)
    {
        rounds_hash.push_back(rounds);
        count++;
    }

    // create the hash function vector
    for (size_t i = 0; i < count; i++)
    {
        hash_functions.push_back(createHashFunction(rounds_hash[i]));
    }
    


    

}