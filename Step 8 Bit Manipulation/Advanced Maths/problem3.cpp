// Sieve of Eratosthenes
// Print all prime numbers till N

#include<bits/stdc++.h>
using namespace std;    

// Brute Force:
// The basic approach is to check whether every number is prime number or not....
// TC: O(N) * O(sqrt(N))
bool primeOptimal(int n){
    int count=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count++;
            if(i!=n/i) count++;
        }
    }
    if(count==2){
        return true;
    }
    else{
        return false;
    }
}


void SieveOfEratosthenesBrute(int number){
    for(int i = 2; i <= number; i++){
    if(primeOptimal(i)){
        cout << i << " ";

    }
}
}




// Optimal Approach:
// O(N) + O(NloglogN) + O(N)
void SieveOfEratosthenesOptimal(int number){
    int prime[number+1];
    for(int i = 2; i <= number; i++){
        prime[i] = 1;
    }

    // Now we are pre computing... i.e if we are given a number... then it will tell whether it is a prime or not....
    // For this.... we will first take 2 from the prime array which we have created above and then mark all the divisors of it to 0.... then again take 2 and mark all the divisors of it 0.... and go till N
    // Now you can optimize the inner loop by going from j = i * i --> j <= N because..... the 2 is already marking a lot of numbers in prime array to zero... so when we do some checks with number 3... then 2 has already done some of the work of it....
    // And we can decrease the first loop to sqrt(n)... because all numbers get covered in it...
    for(int i = 2; i * i <= number; i++){
        if(prime[i] == 1){
            // for(int j = 2 * i; j <= number; j += i){
            for(int j = i * i; j <= number; j += i){
                prime[j] = 0;
            }
        }
    }

    for(int i = 2; i <= number; i++){
        if(prime[i] == 1) cout << i << " ";
    }
}

int main(){
    int number;
    cin>> number;

    SieveOfEratosthenesOptimal(number);
}