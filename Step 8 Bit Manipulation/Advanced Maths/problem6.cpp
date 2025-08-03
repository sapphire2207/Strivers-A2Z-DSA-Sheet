// Count Prime in a range L-R

// We need to answer multiple queries efficiently, where each query consists of two integers L and R. For each query, we must determine the number of prime numbers in the range [L, R].
// Q (number of queries) can be as large as 10⁵.
// L and R are such that L < R, and R can be as large as 10⁶.

// Brute Force Approach:
// Read the number of queries Q.
// For each query, iterate from L to R and count prime numbers.
// To check if a number N is prime, iterate up to √N and check divisibility.
// TC: O(q) * O(r-l+1) * O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool primeOptimal(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Function to count primes in given range queries
    vector<int> countPrime(vector<pair<int, int>>& queries) {
        int q = queries.size();
        vector<int> results;

        for (int i = 0; i < q; i++) {
            int l = queries[i].first;
            int r = queries[i].second;
            int count = 0;

            for (int j = l; j <= r; j++) {
                if (primeOptimal(j)) { // Check for prime
                    count++;
                }
            }

            results.push_back(count);
        }
        return results;
    }
};

// Better Approach Using Sieve of Eratosthenes:
// Instead of checking each number separately, we precompute prime numbers using the Sieve of Eratosthenes, which is O(N log log N).
// Steps for Sieve of Eratosthenes:
// Create an array is_prime[] of size 10⁶ + 1 initialized to True.
// Mark non-prime numbers:
// Set is_prime[0] = False, is_prime[1] = False (since 0 and 1 are not prime).
// Start with 2 (smallest prime) and mark all its multiples as False.
// Repeat for the next unmarked number.
// TC: O(q) * O(r-l+1) + O(nloglogn) => here n = 10^6
class Solution2{
    public:
    vector<int> getSieve(int number) {
        vector<int> sieve(number + 1, 1);
        sieve[0] = sieve[1] = 0;

        for (int i = 2; i * i <= number; i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= number; j += i) {
                    sieve[j] = 0;
                }
            }
        }
        return sieve;
    }

    vector<int> countPrime(vector<pair<int, int>>& queries) {
        int q = queries.size();
        int limit = 1000000; // Fixed limit
        vector<int> prime = getSieve(limit);
        
        // Compute prefix sum for prime counts
        for (int i = 1; i <= limit; i++) {
            prime[i] += prime[i - 1];
        }

        vector<int> results; // Store results for each query
        for (int i = 0; i < q; i++) {
            int l = queries[i].first;
            int r = queries[i].second;

            int count = prime[r] - (l > 0 ? prime[l - 1] : 0);
            results.push_back(count);
        }
        
        return results;
    }
};


// Prefix Sum Optimization for Faster Queries:
// To further speed up query processing, we use Prefix Sum of Primes.
// Steps for Prefix Sum Computation:
// after getting the sieve array..... use it as a prefix sum array to store the primes count till each i....
// prime_count[i] = prime_count[r] + prime[l-1]
// This precomputes cumulative counts of primes up to each
// O(nloglogn) + O(10^6) + O(q)
class Solution3{
    public:
    vector<int> getSieve(int number) {
        vector<int> sieve(number + 1, 1); // Mark all as prime initially
        sieve[0] = sieve[1] = 0; // 0 and 1 are not prime

        for(int i = 2; i * i <= number; i++) {
            if(sieve[i] == 1) {
                for(int j = i * i; j <= number; j += i) {
                    sieve[j] = 0; // Mark multiples of i as non-prime
                }
            }
        }
        return sieve;
    }

    vector<int> countPrime(vector<pair<int, int>>& queries) {
        int N = 1000000; // 10^6
        vector<int> prime = getSieve(N);
        vector<int> results;

        // Compute prefix sum
        for(int i = 2; i <= N; i++) {
            prime[i] += prime[i - 1];
        }

        // Answering queries in O(1)
        for(auto& q : queries) {
            int l = q.first;
            int r = q.second;
            int result = prime[r] - (l > 1 ? prime[l - 1] : 0);
            results.push_back(result);
        }

        return results;
    }
};


// Count primes till n
// Given an integer n, return the number of prime numbers that are strictly less than n.
// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

class Solution {
    public:
        vector<int> getSieve(int number) {
            vector<int> sieve(number + 1, 1);
            sieve[0] = sieve[1] = 0;
    
            for (int i = 2; i * i <= number; i++) {
                if (sieve[i] == 1) {
                    for (int j = i * i; j <= number; j += i) {
                        sieve[j] = 0;
                    }
                }
            }
            return sieve;
        }
    
        int countPrimes(int n) {
            if (n <= 1) return 0;
    
            int limit = 1000000; // Define a fixed limit
            vector<int> prime = getSieve(limit);
    
            // Compute prefix sum for prime counts
            for (int i = 2; i < limit; i++) {
                prime[i] += prime[i - 1];
            }
    
            return prime[n - 1]; // Since we count primes below 'n'
        }
};