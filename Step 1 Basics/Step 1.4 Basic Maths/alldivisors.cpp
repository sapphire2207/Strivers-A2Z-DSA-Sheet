#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

//Brute Force Method:-
// Approach:
// A brute force approach would be to iterate from 1 to n checking each value if it divides n without leaving a remainder. For each divisor found, store it in an array and a count of divisors is maintained. After iterating through all possible values, the size of the array is updated with the count of divisors and the array is returned.

//TC:- O(n)
//SC:- O(1)
void divisorsBrute(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<endl;
    }
}

//Optimal Method:-
// Aproach:
// We can optimise the previous approach by using the property that for any non-negative integer n, if d is a divisor of n then n/d is also a divisor of n. This property is symmetric about the square root of n by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm.

//TC - O(sqrt(n))
//SC - O(1)
void divisorsOptimal(int n){
    // for(int i=1;i*i<=n;i++){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<endl;
            if(i!=n/i){
                cout<<n/i<<endl;
            }
        }
    }
}

//Optimal Method code submission:-
//SC - O(n) where n is the numebr of factors
void divisorsOptimal(int n){
    vector<int> vec;
    //This for loop takes O(sqrt(n))
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            vec.push_back(i);
            if(i!=n/i){
                vec.push_back(n/i);
            }
        }
    }
    //Sorting takes TC of O(nlogn) (where n is the number of factors)
    // sort(vec.begin(),vec.end);
    //This for loop takes O(n) where n is the number of factors
    for(auto it:vec){
        cout<<it<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    divisorsBrute(n);
    divisorsOptimal(n);

    return 0;
}