#include <iostream>
#include <sstream>
#include <vector>
#include <functional>


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

