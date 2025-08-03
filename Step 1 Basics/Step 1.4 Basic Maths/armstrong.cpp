#include<bits/stdc++.h>
using namespace std;

// Method:-
// To check if a number is an armstrong number, we can use the algorithm created in Extract Digits.
// An Armstrong number, also known as a narcissistic number or plenary number, is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
// Number of digits: 3, 153 = 13+53+33
// We extract the digits of the number, raise each digit to the power of the total number of digits in the number. Sum up all the results obtained and check if the sum equals to the original number.

//TC - O(log10(n))+ O(log10(n)) - 'n' is the number of digits
//Since count is the number of times it is getting divisible by 10
//SC - O(1) - No extra space is used
void armstrongg(int n){
    int count=0;
    //Finding the digits of the given number
    int temporary=n;
    while(temporary>0){
        temporary=temporary/10;
        count++;
    }
    //Finding the sum of the digits
    int duplicate=n;
    int armstrongnumber=0;
    while(n>0){
        int lastdigit=n%10;
        armstrongnumber=armstrongnumber+pow(lastdigit,count);
        n=n/10;
    }
    //Verifying with the original number
    if(duplicate==armstrongnumber) cout<<"Armstrong Number";
    else cout<<"Not an Armstrong Number";
}

int main(){
    int n;
    cin>>n;

    armstrongg(n);

    return 0;
}