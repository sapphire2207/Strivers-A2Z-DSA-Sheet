// Number of Distinct Islands (Extension of Number of Islands problem)

// https://takeuforward.org/data-structure/number-of-distinct-islands/

// Problem Statement: Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

// Intuition:
// Consider the following example, the two islands in the first figure might look identical but they are rotated so you can’t say they are the same, hence 2 distinct islands; whereas in the second figure, both islands are the same so only 1 distinct island; resulting in overall 3 distinct islands.

// Consider another example, the two islands in the first figure and another two islands in the second figure are the same, hence total of 2 distinct islands.
// Depending on the shape of the island formed, we count the number of islands.
// The question arises how to store these shapes?
// We can store the shapes in a set data structure, then the set will return unique islands. We can store the coordinates in a vector or a list.
// But how to figure out if the coordinates stored in the set data structure are identical? We can call one of the starting points a base, and subtract the base coordinates from the land’s coordinates (Cell Coordinates - Base coordinates). Now the list will be similar as illustrated.
// NOTE: Make sure to follow a particular traversal and a particular order pattern, so that list ordering remains the same for every cell.
// How do store distinct islands? 
// We've done this type of problem on a number of islands. This is an expansion of the number of islands so refer to that article for the same.
// We can follow either of the traversal techniques. We will be solving it using DFS traversal, but you can apply BFS traversal as well. 
// DFS is a traversal technique that involves the idea of recursion and backtracking. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int row, int col, vector < vector < int >> & vis,
      vector < vector < int >> & grid, vector < pair < int, int >> & vec, int row0, 
      int col0) {
      // mark the cell as visited
      vis[row][col] = 1;

      // coordinates - base coordinates
      vec.push_back({
        row - row0,
        col - col0
      });
      int n = grid.size();
      int m = grid[0].size();

      // delta row and delta column
      int delrow[] = {-1, 0, +1, 0}; 
      int delcol[] = {0, -1, 0, +1}; 

      // traverse all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid unvisited land neighbour coordinates 
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
      }
    }
  public:
    int countDistinctIslands(vector < vector < int >> & grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector < vector < int >> vis(n, vector < int > (m, 0));
      set < vector < pair < int, int >>> st;

      // traverse the grid
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if not visited and is a land cell
          if (!vis[i][j] && grid[i][j] == 1) {
            vector < pair < int, int >> vec;
            dfs(i, j, vis, grid, vec, i, j);
            // store in set
            st.insert(vec);
          }
        }
      }
      return st.size();
    }
};

int main() {
 
  vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
            
  Solution obj;
  cout << obj.countDistinctIslands(grid) << endl;

}

// Output:  3
// Time Complexity: O(N x M x log(N x M)) + O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, the DFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, it will take O(N x M x 4) time. Set at max will store the complete grid, so it takes log(N x M) time.
// Space Complexity ~ O(N x M), O(N x M) for the visited array and set takes up N x M locations at max. 