// src/bloomFilter.h
#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <functional>
#include <string>

class bloomFilter
{
private:
    size_t size;
    std::vector<bool> bits;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
    std::string bad_urls;

public:

// Constructor
    BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFuncs)
        : size(size), hashFunctions(hashFuncs), bits(size, false) {}


    void add (const std::string& url) {
        int hash;
        for (const auto& hashFunction : hashFunctions)
        {
            hash = hashFunction(url) % size;
            bits[hash] = true;
        }
        real_urls.insert(url);
        
    }

    bool check (const std::string& url) {
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

    bool badPostive (const std::string& url) {
        return bad_urls.find(url) != bad_urls.end;
    }

};

#endif

