#include<bits/stdc++.h>
using namespace std;

//Brute Force Method:-
// Intution:
// The GCD of two numbers is the largest number that divides both of them without leaving a remainder. We iterate through all numbers from 1 up to the minimum of the two input numbers, checking if each number is a common factor of both input numbers.
// If a number is a common factor, we update our gcd variable to that number. This process continues until we have iterated through all possible common factors. Finally, we return the gcd variable, which will hold the greatest common divisor of the two input numbers.

//TC - O(min(n1,n2))
//SC - O(1)
void gcdBrute(int n1, int n2){
    int gcd=1;
    for(int i=1;i<=min(n1,n2);i++){
        if(n1%i==0 && n2%i==0){
            gcd=i;
        }
    }
    cout<<gcd<<endl;
}

//Optimal Method:-
// Approach:
// The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number.
// To find the GCD of n1 and n2 where n1 > n2:
// Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
// Once one of them becomes 0, the other number is the GCD of the original numbers.

//TC - O(logx(min(n1,n2)))
//SC - O(1)
//Euclidean Algorithm: gcd(a,b) = gcd(a-b,b) where a>b if a==0, then gcd=b;
//                     gcd(a,b) = gcd(a%b,b) where a>b if a==0, then gcd=b;
void gcdOptimal(int n1, int n2){
    while(n1>0 && n2>0){
        if(n1>n2) n1=n1%n2;
        else n2=n2%n1;
    }
    if(n1==0) cout<<n2;
    else cout<<n1;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;

    gcdBrute(n1,n2);
    gcdOptimal(n1,n2);
}