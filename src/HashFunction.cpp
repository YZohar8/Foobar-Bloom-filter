#include <vector>
#include <functional>
#include <string>

#include "HashFunction.h"

std::function<size_t(const std::string&)> createHashFunction(int rounds) {
    return [rounds](const std::string& str) {
        size_t hash = std::hash<std::string>()(str);
        for (int i = 1; i < rounds; ++i) {
            hash = std::hash<size_t>()(hash); // Apply hash function multiple times
        }
        return hash;
    };
}