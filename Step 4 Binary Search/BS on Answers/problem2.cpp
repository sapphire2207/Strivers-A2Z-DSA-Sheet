// Problem 2:-
// Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the ‘nth root is not an integer, return -1.
// Example 1:
// Input Format: N = 3, M = 27
// Result: 3
// Explanation: The cube root of 27 is equal to 3.

// Example 2:
// Input Format: N = 4, M = 69
// Result: -1
// Explanation: The 4th root of 69 does not exist. So, the answer is -1.

// Brute Force Method:-
// Perform a linear search
// We can guarantee that our answer will lie between the range from 1 to m i.e. the given number. So, we will perform a linear search on this range and we will find the number x, such that
// func(x, n) = m. If no such number exists, we will return -1.
// Note: func(x, n) returns the value of x raised to the power n i.e. xn.
// If func(x, n) == m: This means x is the number we are looking for. So, we will return x from this step.
// If func(x, n) > m: This means we have got a bigger number than our answer and until now we have not found any number that can be our answer. In this case, our answer does not exist and we will break out from this step and return -1.
#include<bits/stdc++.h>
using namespace std;

// Calculating the power using a for loop:
// return 1 if == m
// return 0 if < m
// return 2 if > m
// int calc(int i,int n,int m){
//    long long ans;  
//     for(int j=1;j<=n;j++){
//         ans=ans*i;
//         if(ans>m) return 2;
//     }
//     if(ans==m) return 1;
//     return 0;
// }

// Calculating power using power exponential method:
long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int nthRoot(int n,int m){
    for(int i=1;i<=m;i++){
        long long value = func(i,n);
        if(value == m * 1ll){
            return i;
        }
        else if(value > m * 1ll){
            break;
        }
    }
    return -1;
}

int main(){
    int n=3,m=27;
    int ans = nthRoot(n,m);
    cout<<"nth root of "<<m<<"is: "<<ans<<endl;

    return 0;
}


// Optimal Approach:-
// If func(n, m, mid) == 1: On satisfying this condition, we can conclude that the number ‘mid’ is our answer. So, we will return to ‘mid’.
// If func(n, m, mid) == 0: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// If func(n, m, mid) == 2: the value mid is larger than the number we want. This means the numbers greater than ‘mid’ will not be our answers and the right half of ‘mid’ consists of such numbers. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Finally,  if we are outside the loop, this means no answer exists. So, we will return -1.
// TC:- O(logM)*N --> if used a for loop for calculating the power
// and O(logM)*O(logN) --> if used power exponential method
#include <bits/stdc++.h>
using namespace std;

//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
