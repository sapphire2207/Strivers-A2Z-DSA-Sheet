// Finding Power Set
// Ex: [1,2,3]
// [[], [1], [2], [3], [1,2], [2,3], [1,3], [1,2,3]]

// So basically what you need to do is need to iterate from zero till 2 to the power n where n is the number of elements in the set so 0 till 2^ n minus 1 this is what you need to iterate and for every binary you have to check the zero the first and the second and depending on that you'll create your list and eventually when the list is created you store it in the list of list so the order doesn't matter and eventually we have to return a list which is containing all the list which are basically subsets so once all the subsets are generated you have to take the individual list and put it into the bigger list and this is what you'll be returning right

// TC: O(2^N)*N
// SCis nearby O(2^N)*N
#include<bits/stdc++.h>
vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    int size = nums.size();
    int subsets = 1 << size;
    // O(2^N)
    for (int number = 0; number <= subsets - 1; number++){
        vector<int> list;
        // O(N)
        for (int i = 0; i < size; i++){
            if (number & (1 << i)){
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}