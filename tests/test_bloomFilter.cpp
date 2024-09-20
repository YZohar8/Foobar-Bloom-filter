#include <gtest/gtest.h>
#include "bloomFilter.h"

size_t hash1(const std::string& str) { 
    return std::hash<std::string>()(str);
} 
size_t hash2(const std::string& str) {
    return (std::hash<std::string>()(str) * 17);
} size_t hash3(const std::string& str) {
    return (std::hash<std::string>()(str) + 12345);
}


// Test cases
TEST(BloomFilterTest, MultipleUrls) {
// Create BloomFilter with 100 bits and 2 hash functions 
    std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1, hash2};
    BloomFilter bf(100, hashFunctions);
    bf.add("http://example1.com");
    bf.add("http://example2.com");
    bf.add("http://example3.com");
    EXPECT_TRUE(bf.check("http://example1.com"));
    EXPECT_TRUE(bf.check("http://example2.com"));
    EXPECT_TRUE(bf.check("http://example3.com"));
    EXPECT_FALSE(bf.check("http://example4.com"));
}

TEST(BloomFilterTest, DifferentHashFunctions) {
// Create BloomFilter with 100 bits and 3 hash functions
std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1, hash2, hash3};
    BloomFilter bf(100, hashFunctions);
    bf.add("http://test.com");
    EXPECT_TRUE(bf.check("http://test.com"));
    EXPECT_FALSE(bf.check("http://fakeurl.com"));
}

TEST(BloomFilterTest, CheckFalsePositiveWithMultipleHashFunctions) {
// Create BloomFilter with 100 bits and 2 hash functions
std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1, hash2};
BloomFilter bf(100, hashFunctions);
bf.add("http://example.com");
EXPECT_TRUE(bf.check("http://example.com"));
EXPECT_TRUE(bf.badPostive("http://example.com"));
// Ensure it's not a false positive
EXPECT_FALSE(bf.check("http://otherexample.com"));
}

TEST(BloomFilterTest, AddDuplicateUrl) {
// Create BloomFilter with 100 bits and 2 hash functions
std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1, hash2};
    BloomFilter bf(100, hashFunctions);
    bf.add("http://duplicate.com");
    bf.add("http://duplicate.com");
    EXPECT_TRUE(bf.check("http://duplicate.com"));
}

TEST(BloomFilterTest, EmptyUrl) {
// Create BloomFilter with 100 bits and 2 hash functions
std::vector<std::function<size_t(const std::string&)>> hashFunctions = {hash1, hash2};
    BloomFilter bf(100, hashFunctions);
    bf.add("");
    EXPECT_TRUE(bf.check(""));
    EXPECT_FALSE(bf.check("http://nonemptyurl.com"));
}

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
    EXPECT_TRUE(bf.badPostive("http://example.com"));
    EXPECT_FALSE(bf.badPostive("http://nonexistent.com"));
}
