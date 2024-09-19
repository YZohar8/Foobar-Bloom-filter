#include "bloomFilter.h"



// Constructor
    BloomFilter::BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFuncs)
        : size(size), hashFunctions(hashFuncs), bits(size, false) {}


    void BloomFilter::add (const std::string& url) {
        int hash;
        for (const auto& hashFunction : hashFunctions)
        {
            hash = hashFunction(url) % size;
            bits[hash] = true;
        }
        bad_urls.insert(url);
        
    }

    bool BloomFilter::check (const std::string& url) {
        int hash;
        for (const auto& hashFunction : hashFunctions)
        {
            hash = hashFunction(url) % size;
            if (!bits[hash]) {
                return false;
            }
        }
        return true; // maybe is true postive (true but we claasified this false)
    }

    bool BloomFilter::badPostive (const std::string& url) {
        return (bad_urls.find(url) != bad_urls.end());
    }

