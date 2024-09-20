#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

#include "bloomFilter.h"
#include "HashFunction.h"
#include "logicToBloomFilter.h"

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



