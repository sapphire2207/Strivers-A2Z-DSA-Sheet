#include<bits/stdc++.h>
using namespace std;

// Method:-
// Algorithm:
// Step 1:Initialise an integer revNum to 0. This variable will store the reversed number.
// Step 2: Using a while loop we iterate while n is greater than 0 and at each iteration:
// Calculate the last digit of the number using the modulus operator (N%10) and store it in a variable last digit.
// Update the reversed number by multiplying it with 10 and adding the last digit. This effectively appends the last digit to the end of the reversed number.
// Remove the last digit of the number by dividing it by 10.
// Step 3: After exiting the while loop, return the reversed number.

//TC - O(log10(n)) - 'n' is the number of digits
//Since count is the number of times it is getting divisible by 10
//SC - O(1) - No extra space is used
void reversingNumber(int n){
    int reversenum=0;
    while(n>0){
        int lastdigit= n%10;
        reversenum=reversenum*10+lastdigit;
        n=n/10;  
    }
    cout<<reversenum;
}

int main(){
    int n;
    cin>>n;

    reversingNumber(n);

    return 0;
}