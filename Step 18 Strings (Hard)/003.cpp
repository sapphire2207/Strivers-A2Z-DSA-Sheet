// Hashing in Strings

// Introduction:
// In this article, we will be discussing the Hashing in Strings. Hashing refers to the process of converting a string into a numeric value, called a hash value, using a mathematical formula. It helps in comparing strings, searching efficiently, and solving complex problems like pattern matching.

// Need of Hashing:
// Hashing is essential as it helps in following operations:
// 1. Efficient Comparisons: Comparing large strings is slow. Hash values allow comparison in constant time.
// 2. Faster Lookups: Hash tables like dictionaries or unordered maps use hash values to store and retrieve strings quickly.
// 3. Detect Duplicates or Anagrams: Hashing helps in checking duplicates or determining anagram groups efficiently.
// 4. Pattern Matching: Algorithms like Rabin-Karp use string hashing to find substrings in linear time.

// How Does String Hashing Work?:
// String hashing treats each character as a number and combines them using a mathematical formula. A common formula is Polynomial Rolling Hash. Using this hash value is calculated as follows:
// Hash(s) = (s[0] * p^0 + s[1] * p^1 + s[2] * p^2 + ... + s[n-1] * p^(n-1)) % m
// where, s[i] is the character's ASCII or mapped value (like 'a' = 1),
// p is a prime base (commonly 31 or 53) and
// m is a large prime modulus to avoid overflow and reduce collisions.

// Handling Collisions:
// Two different strings can have the same hash, called a collision. To reduce this, we use a large m (like 1e9+7). We can also use double hashing (combine two different hash functions) or use a good base (p) that spreads values well.

// Example:
// Calculate Hash value of string s = "abc".
// Solution:
// Let us assume p to be 31 and m to be 1e9+9.
// Now, we can map characters as following: 'a' = 1, 'b' = 2 and 'c' = 3.
// Thus, Hash(s) = (1 * 31^0 + 2 * 31^1 + 3 * 31^2) % 1e9+9
// Hash(s) = 2946.
// Therefore, "abc" gets hashed to value 2946.