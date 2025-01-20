#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <regex>


#include "bloomFilter.h"



bool validateUrl(std::string &url) {
    // Regular expression to validate a URL
    const std::regex urlRegex(
        R"(^(https?|ftp)://[^\s/$.?#].[^\s]*$)",
        std::regex::icase // Case-insensitive
    );

    // Check if the URL matches the regex
    return std::regex_match(url, urlRegex);
}

void getUrls(int command, const std::string &url, BloomFilter &bloomFilter) {
    if (!validateUrl(url)) {
        return false;
    }
    if (command == 1) {
        bloomFilter.add(url);
        return true; 
    } else if (command == 2) {
        bool isBlacklisted = bloomFilter.check(url);
        if (isBlacklisted) {
            return bloomFilter.badPostive(url) ? true : false; 
        }
        return false; 
    }
    return false;
}
