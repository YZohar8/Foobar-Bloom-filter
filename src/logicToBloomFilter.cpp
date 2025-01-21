#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <regex>


#include "bloomFilter.h"



bool validateUrl(const std::string &url) {
    const std::regex urlRegex(
        R"(^(https?|ftp)://[^\s/$.?#].[^\s]*$)",
        std::regex::icase
    );
    return std::regex_match(url, urlRegex);
}

bool getUrls(int command, const std::string &url, BloomFilter &bloomFilter) {
    if (!validateUrl(url)) {
        return false;
    }
    if (command == 1) {
        bloomFilter.add(url);
        return true; 
    } else if (command == 2) {
        bool isBlacklisted = bloomFilter.check(url);
        if (isBlacklisted) {
            return bloomFilter.badPostive(url); 
        }
        return false; 
    }
    return false;
}
