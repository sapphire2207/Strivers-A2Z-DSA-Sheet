// Print all prime factors of a Number

// Example: N = 60
// 2, 3, 5

// Example: N = 780
// 2, 3, 5, 13

// Brute Force:
// First find all the divisors and then check which are prime.....
// TC: O(N * sqrt(N))
// SC: We are just using the space for storing the answers...
#include<bits/stdc++.h>
using namespace std;

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

void printAllPrimeFactorsBrute(int number){ 
    vector<int> answer;
    for(int i = 2; i <= number; i++){
        if(number % i == 0){
            if(primeOptimal(i)){
                answer.push_back(i);
            }
        }
    }
}

// Better Solution:
// Instead of looping till N for the divisors.... we can loop till sqrt of n to find out the divisors....
// TC is nearly equal to O(srt(n) * 2 * sqrt(n)) => here remember that the prime check is not happening every time...so that is why the exact time complexity can't be computed
void printAllPrimeFactorsBetter(int number){ 
    vector<int> answer;
    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            if(primeOptimal(i)){
                answer.push_back(i);
            }
            if(number / i != i){
                if(primeOptimal(number/i)){
                    answer.push_back(i);
                }
            }
        }
    }
}

// Better Approach 2:
// So first take the number and divide it by 2 till it is possible... then divide it by 3 till it is possible... and repeat this till the original number becomes zero...
// This works because.... 2 and 3 are primes that is okay... but when it comes to 4.... since we will always divide the number by 2 till wherever it is possible.... so when the i becomes 4... it's already considered...
// If N = 780.... TC: O(13)... but in the worst case if the given number is actually a prime number.... the TC remains same i.e O(N*logN)
// ...logN because we are dividing it....
void printAllPrimeFactorsBetterTwo(int number){
    vector<int> answer;
    for(int i = 2; i <= number; i++){
        if(number % i == 0){
            answer.push_back(i);
            while(number % i == 0){
                number = number / i;
            }
        }
    }
}

// Optimal Approach:
// Here you can maintain the same approach as better 2 solution... but just loop till sqrt(number)....
// TC: O(sqrt(N)*logN)
void printAllPrimeFactorsOptimal(int number){
    vector<int> answer;
    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            answer.push_back(i);
            while(number % i == 0){
                number = number / i;
            }
        }
    }
    if(number != 1) answer.push_back(number);
}





int main(){
    int number;
    cin >> number;

    printAllPrimeFactorsBrute(number);
    printAllPrimeFactorsBetter(number);
}