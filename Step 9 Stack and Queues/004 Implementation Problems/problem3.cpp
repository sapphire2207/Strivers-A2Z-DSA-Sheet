// Find the Celebrity

// The given problem presents a scenario where you're at a party with n people, each labeled with a unique number between 0 and n - 1. Your goal is to identify a possible celebrity among them. A celebrity is defined by two conditions: first, every other person at the party knows the celebrity, and second, the celebrity does not know anyone else at the party.
// The output of your task is to return the unique label of the celebrity if one exists, or -1 if there is no celebrity present.

// Brute Force:
// Check each person i if:
// They don’t know anyone (matrix[i][j] == 0 for all j).
// They are known by everyone (matrix[j][i] == 1 for all j ≠ i).
// If a person satisfies both conditions, they are the celebrity.
// TC: O(N*N) + O(N)
// SC: O(2N)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findCelebrity(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> knowMe(m, 0);
        vector<int> iKnow(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(knowMe[i] == n-1 && iKnow[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

// Optimal:
// Use two pointers: top = 0, bottom = n-1.
// Elimination Process:
// If matrix[top][bottom] == 1 → top is not a celebrity (move top up).
// If matrix[top][bottom] == 0 → bottom is not a celebrity (move bottom down).
// After elimination, top is the potential celebrity.
// Validation:
// Check if the potential celebrity is known by everyone.
// Ensure they don’t know anyone.
// TC: O(2N) 
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findCelebrity(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int down = n-1;
        while(top < down){
            if(matrix[top][down] == 1){
                top++;
            }
            else if(matrix[down][top] == 1){
                down--;
            }
            else{
                top++;
                down--;
            }
        }
        if(top > down) return -1;
        if(top == down){
            for(int i = 0; i < n; i++){
                if(i == top) continue;
                if(matrix[top][i] == 0 && matrix[i][top] == 1){

                }
                else{
                    return -1;
                }
            }
        }
        return top;
    }
};