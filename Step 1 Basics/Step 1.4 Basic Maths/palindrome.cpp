#include<bits/stdc++.h>
using namespace std;

// Method:-
// To check if a number is a palindrome, we can use the algorithm created in Extract Digits as now we extract the digits of the number to create a reversed number. We then compare the reversed number with the original number. If they are equal, the original number is a palindrome. If they are not equal the original number is not a palindrome.

//TC - O(log10(n)) - 'n' is the number of digits
//Since count is the number of times it is getting divisible by 10
//SC - O(1) - No extra space is used
void palindromee(int n){
    int duplicate=n;
    int reversenum=0;
    while(n>0){
        int lastdigit= n%10;
        reversenum=reversenum*10+lastdigit;
        n=n/10;  
    }
    if(duplicate==reversenum) cout<<"Palindrome";
    else cout<<"Not a Palindrome";
}

int main(){
    int n;
    cin>>n;

    palindromee(n);

    return 0;
}