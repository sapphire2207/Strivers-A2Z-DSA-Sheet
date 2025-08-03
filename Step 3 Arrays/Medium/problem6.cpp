// Problem 6:- Best time to Buy and Sell Stock

// Ex: arr={7,1,5,3,6,4} (days=6) ==> Here we need to first buy a stock and then sell that particular stock, So the given array tells us about the price of the stock, means on first day the stock price is 7rs, on second day it's 1rupee, on third day it's 5rs and etc
// For example you buy a stock at 1rupee on day 2 and sell it on day 5 at 6rs, so your profit is 5rs, So the aim of the problem is it to maximize the profit by giving us suggestions so that we can buy and sell the stock at that particular day.

// Optimal Solution:-
// So the logic is: if you are selling the stock on ith day, then you will be buying it on the minimum price day may be from 0 to (i-1)th day
// So carry a variable which tells you about the minmum price day, then the cost or profit you will be getting will be equal to a[i] - min ==> selling day price - minimum day price
// Now keep on updating the maximum profit
// TC:- O(N)
// SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void stock(vector<int>& arr, int n){
    int minimum=arr[0];
    int profit=0;
    for(int i=1;i<n;i++){
        minimum=min(minimum,arr[i]);
        profit= max(profit,arr[i]-minimum);
    }
    cout<<profit<<endl;
}

int main(){
    int n=6;
    vector<int> arr={7,1,5,3,6,4};

    stock(arr,n);

    return 0;
}