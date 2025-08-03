// Lemonade Change

// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
// Note that you do not have any change in hand at first.
// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
// Example 1:
// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.

// Optimal Approach:
// We can approach this question by maintaining two counters to keep track of the available 5$ and 10$ bills. We iterate through the customers and provide change accordingly.
// If a customer pays with a 5$ bill, we simply keep it as we will not have to provide any change. If the customer pays with a 10$ bill, we check if there is at least one 5$ bill available to provide change and decrement the counter.
// If the customer uses a 20$ bill, we provide change using 5$ and 10$ bills or with three 5$ bills. If at any point, we are not able to provide the required change we return false.
// Otherwise, if we successfully serve all customers with the correct change, we can return true.
// TC: O(N)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int n = bills.size();
        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                fives++;
            }
            else if(bills[i] == 10){
                if(fives){
                    fives--;
                    tens++;
                }
                else{
                    return false;
                }
            }
            else{
                if(tens && fives){
                    tens--;
                    fives--;
                }
                else if(fives >= 3){
                    fives -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};