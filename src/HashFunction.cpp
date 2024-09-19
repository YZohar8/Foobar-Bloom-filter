#include <vector>
#include <functional>

#include "HashFunction.h"

std::function<size_t(const std::string&)> createHashFunction (int rounds) {
    return [rounds](const std::string& str) -> size_t {
        std::hash<std::string> hasher;
        size_t hash_value = hasher(str); // Initial hash

        // Apply std::hash 'n - 1' more times
        for (int i = 1; i < rounds; ++i) {
            hash_value = hasher(std::to_string(hash_value)); // Re-hash the result
        }

        return hash_value;
    };
}