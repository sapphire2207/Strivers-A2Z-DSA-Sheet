#include<bits/stdc++.h>
using namespace std;

//Brute Force Method:-
// Approach:
// We can iterate through numbers from 1 to n, counting how many of these numbers divide n without a remainder. If exactly two numbers do, so n is prime otherwise it is not prime.

//TC - O(N)
//SC - O(1)
void primeeBrute(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0) count++;
    }
    if(count==2) cout<<"Prime Number";
    else cout<<"Non-Prime Number";
}

//Optimal Method:-
// Approach:
// We can optimise the algorithm by only iterating up to the square root of n when checking for factors. This is because if n has a factor greater than its square root, it must also have a factor smaller than its square root.This property is symmetric about the square root of n by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm.

//TC  - O(sqrt(n))
//SC - O(1)
void primeeOptimal(int n){
    int count=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count++;
            if(i!=n/i) count++;
        }
    }
    if(count==2) cout<<"Prime Number";
    else cout<<"Non-Prime Number";
}

int main(){
    int n;
    cin>>n;

    primeeBrute(n);
    primeeOptimal(n);

    return 0;
}