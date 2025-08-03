#include<bits/stdc++.h>
using namespace std;

// Method 1:-
// Approach:
// To count the number of digits in a number, we can use the algorithm created in Extract Digits as now instead of extracting digits we are simply creating a counter to count the number of digits in the number..

// Algorithm:   
// Step 1:Initialise a counter to store the number of digits.
// Step 2:While N is greater than 0, execute the following:
// Increment the counter by 1
// Update N by removing its last digit by performing a modulo 10 (%10) operation on it.
// Step 3:After exiting the while loop, we return the counter as the number of digits.

// TC - O(log10(n)) - 'n' is the input number
// Since count is the number of times it is getting divisible by 10
// SC - O(1) - No extra space is used
void digitCount(int n){
    int count=0;
    while(n>0){
        n=n/10;
        count+=1;
    }
    cout<<count;
}

int main(){
    int n;
    cin>>n;

    digitCount(n);

    return 0;
}

//Method 2: (int)(log10(n) + 1); Since count is the number of times it is getting divisible by 10
// Use logarithm base 10 to count the number of digits. As The number of digits in an integer = the upper bound of log10(n).
// This works because the logarithm base 10 of a number tells us the exponent needed to reach that number from 10. Taking the floor function and adding 1 gives the correct digit count.

// TC: O(1)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

int count_digits( int n ){
  int digits = floor(log10(n) + 1);
  return digits;
}

int main(){
   int n = 12345;
   cout<< "Number of digits in "<<n<<" is "<<count_digits(n);
   return 0;
}

