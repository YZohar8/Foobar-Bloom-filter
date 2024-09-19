#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

#include "bloomFilter.h"
#include "HashFunction.h"



bool isValidInput (std::string& input) {
    for (char c : input)
    {
        if (!std::isdigit(c) && !std::isspace(c)){
            return false;
        }
    }
    return true;
    
}

void getUrls (BloomFilter bloomFilter) {
    while (true) {
        int command;
        std::string url;
        std::string line;

        // receive new line
        std::getline(std::cin, line);
        std::istringstream iss(line);


        if (!(iss >> command >> url)) {
            continue; // Skip invalid lines if have problem in the data
        }

        if (command == 1) {
            bloomFilter.add(url);
        } else if (command == 2) {
            bool isBlacklisted = bloomFilter.check(url);
            std::cout << (isBlacklisted ? "true" : "false");
            if (isBlacklisted) {
                std::cout << " "
                          << (bloomFilter.badPostive(url) ? "true" : "false");
            }
            std::cout << std::endl;
        } else {
            continue;
        }
    }
}

int getFirstLine (size_t& bloom_size, std::vector<size_t>& rounds_hash) {
    int count = 0;
    std::string line;

    do {
        do
        {
            std::getline(std::cin, line);
        } while (!isValidInput(line));

        std::istringstream iss(line);

        iss >> bloom_size;
        int rounds;
        while (iss >> rounds)
        {
            rounds_hash.push_back(rounds);
            count++;
        }

    } while (count == 0);
    return count;
}


int main() {

    std::string line;
    size_t bloom_size;
    std::vector<size_t> rounds_hash;
    std::vector<std::function<size_t(const std::string&)>> hash_functions;

    std::cout << "enter input\n";


    int count = getFirstLine( bloom_size , rounds_hash);
    // create the hash function vector
    for (size_t i = 0; i < count; i++)
    {
        hash_functions.push_back(createHashFunction(rounds_hash[i]));
    }
    //create bloom filter that based an information
    BloomFilter bloomFilter(bloom_size, hash_functions);

    getUrls(bloomFilter);

    }



