// Online Stock Span

// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
// For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:
// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.

// Example 1:
// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]
// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
// stockSpanner.next(85);  // return 6

// Brute Force:
// Maintain a dynamic list to store stock prices.
// For each new price, iterate backward and count consecutive smaller or equal prices.
// TC: O(number of days)
// SC: O(total number of next calls till now)
#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    vector<int> arr;

    StockSpanner() {
        arr = {};
    }
    
    int next(int price) {
        arr.push_back(price);
        int count = 1;
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] <= price) { 
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};

// Optimal Solution:
// Use a stack to store (price, span) pairs.
// Instead of iterating back, use the stack to efficiently find the previous greater element.
// If a smaller or equal price exists in the stack, accumulate its span.
// TC: O(2N)
// SC: O(N)
#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = -1;
    StockSpanner() {
        index = -1;
        while (!st.empty()) st.pop();
    }
    
    int next(int price) {
        index = index + 1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return ans;
    }
};
