// src/bloomFilter.h
#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <functional>
#include <string>
# include <set>

// class bloom filter
class BloomFilter
{
private:
    size_t size;
    std::vector<bool> bits;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
    std::set<std::string> bad_urls;

public:

// Constructor
    BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFuncs);


    void add (const std::string& url);

    bool check (const std::string& url);

    bool badPostive (const std::string& url);

};

#endif
