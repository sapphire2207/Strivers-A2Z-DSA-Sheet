//Problem 1:- TWO SUM
//You will be given an array for ex:- [2,6,5,8,11] and the given target is for example 14
//So in the first variety of problem given you should tell whther the given target is present in the given array or not
//And in the second variery of problem you should given the indexes which lead to the given target

//BRUTE FORCE METHOD:-
//Here we are taking the first element and then checking the sum with all the other elements to get the target and repeatedly do this process
//TC:- O(N^2)
//SC:- O(1)
//Variant 1:-
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}

//Variant 2:-
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}


//BETTER SOLUTION:-
//First take a hash map, then iterate through all the elements, now hash each and every element with the current index of the pointer if the other element which leads to the sum is not present, if the other element which leads to sum is present return "YES" or else return the current index and the index which leads to sum
//TC:- O(N*logN) -> for ordered map and O(N*N) -> for the unordered map in the worst case and in the best case it is of O(N*1)
//SC:- O(N)
//Variant 1:-
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num; 
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}

int main()
{
    int n = 5;                  
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}

//Variant 2:-
#include <bits/stdc++.h>
using namespace std;

vector<int> twooSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twooSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}


//OPTIMAL SOLUTION:-
//Here first we sort the array,and then take two pointers one at the start and the other at the end, now check whther the pointer's indexes lead to the target, if yes submit, if the sum is less, then increase the starting pointer, if sum is greater then move the end pointer backward
//TC:- O(N) + O(N*logN), where N = size of the array --> The loop will run at most N times. And sorting the array will take N*logN time complexity. 
//SC:- O(1) as we are not using any extra space --> Here we are distorting the given array. So, if we need to consider this change, the space complexity will be O(N).
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

int main()
{
    int n = 5;         
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
// For variant 2, we can store the elements of the array along with its index in a new array. Then the rest of the code will be similar. And while returning, we need to return the stored indices instead of returning “YES”. But for this variant, the recommended approach is approach 2 i.e. hashing approach.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    vector<pair<int, int>> sample;

    // Store value and original index
    for (int i = 0; i < nums.size(); i++) {
        sample.push_back({nums[i], i});
    }

    // Sort the sample by value (pair.first)
    sort(sample.begin(), sample.end());

    int left = 0, right = sample.size() - 1;

    // Two-pointer search
    while (left < right) {
        int sum = sample[left].first + sample[right].first;

        if (sum == target) {
            ans.push_back(sample[left].second);  // Original index of left element
            ans.push_back(sample[right].second); // Original index of right element
            break;  // Found the pair, exit loop
        }
        else if (sum < target) {
            left++;  // Increase sum by moving left pointer
        }
        else {
            right--;  // Decrease sum by moving right pointer
        }
    }
    return ans;
}
};