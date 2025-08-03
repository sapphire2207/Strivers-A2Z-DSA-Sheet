// Rotten Oranges : Min time to rot all oranges : BFS

// Problem Statement: You will be given an m x n grid, where each cell has the following values : 
// 2  -  represents a rotten orange
// 1  -  represents a Fresh orange
// 0  -  represents an Empty Cell
// Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten. 
// Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.

// Approach:
// The idea is that for each rotten orange, we will find how many fresh oranges there are in its 4 directions. If we find any fresh orange we will make it into a rotten orange. One rotten orange can rotten up to 4 fresh oranges present in its 4 directions. For this problem,  we will be using the BFS ( Breadth-First Search ) technique.

// -> First of all we will create a Queue data structure to store coordinate of Rotten Oranges
// We will also have variables as:
// Total_oranges - It will store total number of oranges in the grid ( Rotten + Fresh )
// Count - It will store the total number of oranges rotten by us . 
// Total_time - total time taken to rotten.
// -> After this, we will traverse the whole grid and count the total number of oranges in the grid and store it in Total_oranges. Then we will also push the rotten oranges in the Queue data structure as well.
// -> Now while our queue is not empty,  we will pick up each Rotten Orange and check in all its 4 directions whether a Fresh orange is present or not. If it is present we will make it rotten and push it in our queue data structure and pop out the Rotten Orange which we took up as its work is done now.
// -> Also we will keep track of the count of rotten oranges we are getting.
// -> If we rotten some oranges, then obviously our queue will not be empty. In that case, we will increase our total time. This goes on until our queue becomes empty. 
// -> After it becomes empty, We will check whether the total number of oranges initially is equal to the current count of oranges. If yes, we will return the total time taken, else will return -1 because some fresh oranges are still left and can’t be made rotten.
// Time Complexity: O ( n x n ) x 4    
// Reason: Worst-case - We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions
// Space Complexity: O ( n x n )
// Reason: worst-case -  If all oranges are Rotten, we will end up pushing all rotten oranges into the Queue data structure

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int countFresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    countFresh++;
                }
            }
        }

        int timer = 0;
        vector<int> dRow = {-1, 0, +1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            timer = max(timer, tm);
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = r + dRow[i];
                int ncol = c + dCol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, tm + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != countFresh) return -1;
        return timer;
    }
};