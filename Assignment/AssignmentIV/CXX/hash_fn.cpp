/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
   2025/11/19 Modified by 李小權 《s1101550@yzu.edu.tw》
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    long long safeKey = key;
    if (safeKey < 0) safeKey = -safeKey;
    return (int)(safeKey % m);  // Basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long long hash = 0;
    const int p = 31; // Small prime number (usually 31 or 53)
    
    // Formula: hash = (hash * 31 + char) % m
    // We calculate the sum hash first, then modulo m at the end or step by step.
    for (char c : str) {
        hash = (hash * p + c); 
    }
    return (int)(hash % m);
}
