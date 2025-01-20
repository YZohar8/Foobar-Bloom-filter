#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

#include "bloomFilter.h"
#include "HashFunction.h"
#include "global.h"
#include "server.h"

int main() {


    std::vector<std::function<size_t(const std::string&)>> hash_functions;

    // create the hash function vector
    for (size_t i = 0; i < countToResetTheBloomFilter; i++)
    {
        hash_functions.push_back(createHashFunction(roundsHashToReset[i]));
    }
    //create bloom filter that based an information
    BloomFilter bloomFilter(bloomFilterSizeToReset, hash_functions);
    runServer(bloomFilter);
    }



