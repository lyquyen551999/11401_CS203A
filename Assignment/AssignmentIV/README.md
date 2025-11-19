# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [李小權]  
Email: [lyquyen551999@gmail.com]  

## My Hash Function
### Integer Keys 
  - Formula / pseudocode:
    ```text
      function myHashInt(key, m):
      return abs(key) % m
    ```
  - Rationale: I chose the Division Method because it is simple, fast, and effective when the table size ($m$) is a prime number. By taking the modulus, we ensure the index falls within the valid range $[0, m-1]$. Using the absolute value ensures that negative keys do not produce negative indices.

### Non-integer Keys
  - Formula / pseudocode:
    ```text
      function myHashString(str, m):
        hash = 0
        p = 31
        for char c in str:
            hash = (hash * p + c)
        return hash % m
    ```
  - Rationale: I used the Polynomial Rolling Hash algorithm.
  1. Why 31? 31 is a small prime number close to a power of 2 ($31 = 2^5 - 1$). This works well for English strings (lowercase letters) and helps distribute keys uniformly.
  2. Position Matters: The formula $(s[0]*p^{n-1} + ... + s[n-1])$ ensures that anagrams like "act" and "cat" produce different hash values, unlike simply summing ASCII values.

## Experimental Setup
  - Table sizes tested (m): 10, 11, 37
  - Test dataset:
    - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
    - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
  - Compiler: GCC and G++
  - Standard: C23 and C++23

## Results
  | Table Size (m) | Index Sequence (Integers 21-30) | Observation                                                                                                |
  |----------------|---------------------------------|------------------------------------------------------------------------------------------------------------|
  | 10             | 1, 2, 3, 4, 5, 6, 7, 8, 9, 0    | High Collision: Values like 21 and 51 map to the same index (1). Pattern repeats exactly every 10 numbers. |
  | 11             | 0, 0, 1, 2, 3, 4, 5, 6, 7, 8    | Good Distribution: The modulo 11 breaks the decimal pattern of the input data.                             |
  | 37             | 21, 22, 23, ...                 | Sparse Distribution: No collisions for this small dataset because $m >$ number of keys.                    |

## Compilation, Build, Execution, and Output

### Compilation
  - The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:

    ```bash
    # Build both C and C++ versions
    make all

### Execution
  - Run the compiled binary:

    ```bash
    ./hash_function_cpp
    ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...
  51      1  <-- Collision with 21
  52      2  <-- Collision with 22

  === Table Size m = 11 (Prime) ===
  Key     Index
  -----------------
  21      10
  22      0
  51      7
  52      8
  (Indices are more spread out relative to the key values)
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     2
  dog     4
  bat     2  <-- Collision with "cat"
  cow     5
  ant     8

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     5
  dog     0
  bat     10
  cow     9
  ant     8
  (Fewer collisions observed compared to m=10)

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     7
  dog     32
  bat     5
  cow     10
  ant     8
  (Wide distribution, effectively no collisions for this set)
  ```

## Analysis

  1. Prime vs Non-prime m: - When m=10 (non-prime), the integer hash function key % 10 simply takes the last digit. Since our data (21, 51) shares the same last digit, collisions are guaranteed and frequent.
    - When m=11 or 37 (primes), the indices are calculated based on the whole number, resulting in a much more uniform distribution ("Avalanche effect").
  2. String Hashing: - The polynomial rolling hash effectively scattered similar words. For example, "cat" and "bat" differ by only one letter, but their hash values modulo 37 were distinct (7 vs 5) 

## Reflection

  1. Choice of Table Size: The experiment confirms that choosing a prime number for the table size is critical, especially when using the division method. It helps avoid patterns in the input data (like sequences of numbers ending in same digits) from causing clustering.
  2. Hash Function Design: For strings, simply summing ASCII characters is bad (swapped letters give same hash). The rolling hash (multiplying by a prime $p=31$) solves this by giving weight to character positions.

