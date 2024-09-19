#include <gtest/gtest.h>
#include "bloomFilter.h"

size_t hash1 (const std::string& str) {
    return std::hash<std::string>(str);
}
size_t hash1 (const std::string& str) {
    return (std::hash<std::string>(str) * 17);
}


// Test cases
TEST(BloomFilterTest, BasicOperations) {
    // Create BloomFilter with 100 bits and 2 hash functions
    std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1, hash2};
    BloomFilter bf(100, hashFunctions);

    bf.add("http://example.com");
    EXPECT_TRUE(bf.check("http://example.com"));
    EXPECT_FALSE(bf.check("http://nonexistent.com"));
}

TEST(BloomFilterTest, FalsePositive) {
    // Create BloomFilter with 100 bits and 1 hash function
    std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1};
    BloomFilter bf(100, hashFunctions);

    bf.add("http://example.com");
    EXPECT_TRUE(bf.check("http://example.com"));
    EXPECT_FALSE(bf.badPostive("http://example.com"));
    EXPECT_TRUE(bf.badPostive("http://nonexistent.com"));
}