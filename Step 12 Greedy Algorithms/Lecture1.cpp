// Assign Cookies

// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// Example 1:
// Input:g = [1, 5, 3, 3, 4], s = [4, 2, 1, 2, 1, 3]    
// sort: g = [1, 3, 3, 4, 5], s = [1, 1, 2, 2, 3, 4]       
// Output: 3
// Explanation: You have 5 children and 6 cookies. The greed factors of the 5 children are 1, 5, 3, 3, and 4. The sizes of the 6 cookies are 4, 2, 1, 2, 1, and 3.     
// The child with greed factor 1 can be satisfied with the cookie of size 1.
// One child with greed factor 3 can be satisfied with the cookie of size 3.
// One child with greed factor 3 can be satisfied with the cookie of size 4.
// Hence, the output is 3. 


// Optimal Approach:
// Greedy Algorithms are approached to solve problems by making the current best choice at each stage with the hope of getting the best answer overall as well. At each step of the algorithm, we choose the best possible option available without considering the consequences of the choice in future steps.
// To solve this question, we sort the greed and cookies array to easily make decisions about which cookie to assign to which child. We then iterate over the sorted arrays comparing elements and assigning the smallest available cookie with the least greedy child.
// This way we are able to leave larger cookies for potentially gredier children so that we are able to maximise the overall satisfaction.

// Sort them for easily matching...
// See keep a left pointer at greed array.... and right pointer at cookie's size array..
// Now move the left pointer only when you get a greed value... if you don't get someone means for the next children also you won't be getting a cookie (since the arrays are sorted)
// if you get someone move both pointers
// TC: O(nlogn + mlogm + m)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int n = g.size();
        int m = s.size();
        int left = 0; // is at greed array (g)
        int right = 0; // cookie array (s)
        while(left < n && right < m){
            if(g[left] <= s[right]){
                left++;
            }
            right++;
        }
        return left;
    }
};