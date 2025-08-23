// Buy and Sell Stock - II | (DP -36)

// Problem Statement: 
// Buy and Sell Stock - II 
// We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.

// Memoization Approach
// Every day, we will have two choices, either to do nothing and move to the next day or to buy/sell (based on the last transaction) and find out the profit. Therefore we need to generate all the choices in order to compare the profit. As we need to try out all the possible choices, we will use recursion.

// Steps to form the recursive solution: 
// We will first form the recursive solution by the three points mentioned in the Dynamic Programming Introduction. 
// Step 1: Express the problem in terms of indexes.
// We need to think in the terms of the number of days, therefore one variable will be the array index( say ind). Next, we need to respect the condition that we can’t buy a stock again, that is we need to first sell a stock, and then we can buy that again. Therefore we need a second variable ‘buy’ which tells us on a particular day whether we can buy or sell the stock. We can generalize the function as :
// Step 2: Try out all possible choices at a given index.
// Every day, we have two choices:
// To either buy/sell the stock(based on the buy variable’s value). 
// To do nothing and move on to the next day.
// We need to generate all the choices. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.
// Case 1: When buy == 0, we can buy the stock.
// If we can buy the stock on a particular day, we have two options:
// Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘buy’ variable value will still remain 0, indicating that we can buy the stock the next day.
// Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -Arr[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have bought the stock, the ‘buy’ variable value will change to 1, indicating that we can’t buy and only sell the stock the next day.
// Case 2: When buy == 1, we can sell the stock.
// If we can buy the stock on a particular day, we have two options:
// Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the ‘buy’ variable value will still remain at 1, indicating that we can’t buy and only sell the stock the next day.
// Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +Arr[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have sold the stock, the ‘buy’ variable value will change to 0, indicating that we can buy the stock the next day.
// The figure below gives us the summary:
// Step 3:  Return the maximum 
// As we are looking to maximize the profit earned, we will return the maximum value in both cases.
// The final pseudocode after steps 1, 2, and 3:
// Base Cases:
// If ind==n, it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.

// Steps to memoize a recursive solution:
// If we draw the recursion tree, we will see that there are overlapping subproblems. In order to convert a recursive solution the following steps will be taken:
// Create a dp array of size [n][2]. The size of the input array is ‘n’, so the index will always lie between ‘0’ and ‘n-1’. The ‘buy’  variable can take only two values: 0 and 1. Therefore we take the dp array as dp[n][2]
// We initialize the dp array to -1.
// Whenever we want to find the answer to particular parameters (say f(ind, buy)), we first check whether the answer is already calculated using the dp array(i.e dp[ind][buy]!= -1 ). If yes, simply return the value from the dp array.
// If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[ind][buy] to the solution we get.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if (buy == 1) {
            profit = max(-prices[ind] + helper(ind + 1, 0, n, prices, dp),
                         0 + helper(ind + 1, 1, n, prices, dp));
        } else {
            profit = max(prices[ind] + helper(ind + 1, 1, n, prices, dp),
                          0 + helper(ind + 1, 0, n, prices, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, n, prices, dp);
    }
};

// Complexity Analysis
// Time Complexity: O(N*2) 
// Reason: There are N*2 states therefore at max ‘N*2’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum
// Space Complexity: O(N*2) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*2)).

// Tabulation Approach
// To convert the memoization approach to a tabulation one, create a dp array with the same size as done in memoization. We can set its type as bool and initialize it as false.
// First, we declare the dp array of size [n+1][2] as zero.
// Next, we set the base condition, we set dp[n][0] = dp[n][1] = 0(the case when we had exhausted the number of days of the stock market).
// Next, we set two nested for loops, the outer loop (for variable ind) moves from  n-1 to 0 and the inner loop (for variable buy) moves from 0 to 1.
// In every iteration, we calculate the value according to the memoization logic.
// At last, we will print dp[0][0] as our answer.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));

        dp[n][0] = dp[n][1] = 0;

        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};

// Complexity Analysis
// Time Complexity: O(N*2) 
// Reason: There are two nested loops that account for O(N*2) complexity.
// Space Complexity: O(N*2)
// Reason: We are using an external array of size ‘N*2’. Stack Space is eliminated.

// Space Optimization Approach
// If we closely look the relation,
// dp[ind][buy] = max( dp[ind+1][buy] , max( dp[ind+1][!buy])
// We see that to calculate a value of a cell of the dp array, we need only the next column values(say ahead). So, we don’t need to store an entire 2-D array. Hence we can space optimize it.
// We set the ahead column as 0 (base condition)
// Then we set the nested loops to calculate the cur column values.
// We replace dp[ind] with cur and dp[ind+1] with ahead in our memoization code.
// After the inner loop execution, we set ahead as cur for the next outer loop iteration.
// At last, we return cur[0] as our answer.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);

        ahead[0] = ahead[1] = 0;

        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }

        return ahead[1];
    }
};

// Complexity Analysis
// Time Complexity: O(N*2)
// Reason: There are two nested loops that account for O(N*2) complexity
// Space Complexity: O(1)
// Reason: We are using an external array of size ‘2’.