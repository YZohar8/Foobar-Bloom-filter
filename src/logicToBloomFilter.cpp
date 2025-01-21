#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <regex>


#include "bloomFilter.h"

using namespace std;



bool validateUrl(const std::string &url) {
    const std::regex urlRegex(
        R"(\b(?:https?:\/\/|www\.)?[a-zA-Z0-9-]+\.[a-zA-Z]{2,}(?:\.[a-zA-Z]{2,})?(?:\/[^\s]*)?\b)",
        std::regex::icase
    );
    bool result = std::regex_match(url, urlRegex);
    return result;
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
