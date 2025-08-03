// Print the prime factorization of given queries..

// For example:
// Queries = 3
// 12 = 2, 2, 3
// 16 = 2, 2, 2, 2
// 60 = 2, 2, 3, 5

#include<bits/stdc++.h>
using namespace std;

// Brute Force:
// The approach is to start from 2 and keep on dividing the first query till it is possible... then try with 3.. do this till sqrt(n)....
// TC: O(Queries) * O(sqrt(n))
vector<int> printPrimeFactorizationBrute(int query){
    vector<int> answer;
    for(int i = 2; i <= sqrt(query); i++){
        if(query % i == 0){
            while(query % i == 0){
                answer.push_back(i);
                query = query / i;
            }
        }
    }
    if(query != 1) answer.push_back(query);
}
// Continuation of Brute....
// for(int i = 0; i < queries.size(); i++){
//     list = printPrimeFactorizationBrute(queries[i]);
//     // print the list...
// }

// Optimal Solution:
// Use the same method as Sieve of Eratosthenes.. here mark all the numbers in the smallest prime factor matrix with the index number itself...then start iterating from 2.... Now mark all the factors of 2 with 2.... then mark all the factors of 3 (starting from 3*3 only.... because other factors have been counted by 2....)... then when you want the spf of any number you get it...
// So after this what you do is.... you iterate through the queries and take the first query.... then take the spf of it and print it... then divide that query again with the spf... by doing continously you'll get the entire prime factorisation....
// TC: O(NloglogN) + O(queries*logN)
// SC: O(N)
int spf(int query){
    int spfMatrix[10^5 + 1];
    for(int i = 1; i <= 10^5; i++) spfMatrix[i] = i;
    for(int i = 2; i * i <= 10^5; i ++){
        if(spfMatrix[i] == i){
            for(int j = i*i; j <= 10^5; j += i){
                if(spfMatrix[j] == j){
                    spfMatrix[j] = i;
                }
            }
        }
    }
}

int main(){
    vector<int> queries = {12, 16, 60};
    vector<int> list;

    for(int i = 0; i < queries.size(); i++){
        list = printPrimeFactorizationBrute(queries[i]);
        // print the list...
    }

    for(int i = 0; i < queries.size(); i++){
        int query = queries[i];
        while(query != 1){
            cout << spf(query);   
            query = query / spf(query);
        }
    }
}