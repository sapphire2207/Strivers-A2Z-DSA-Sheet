// Detect Cycle in an Undirected Graph (using DFS)

// Problem Statement: Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

// Intuition:
// The cycle in a graph starts from a node and ends at the same node. DFS is a traversal technique that involves the idea of recursion and backtracking. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes. The intuition is that we start from a source and go in-depth, and reach any node that has been previously visited in the past; it means there's a cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}

// Output:  0
// Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
// Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.
// (Striver's example)
// Step 6: Go to 3
// dfs(3, 6)
// → vis[3] = 1
// → neighbors = [1, 4, 6]
// ✅ Now here is where the condition is triggered:
// adjacentNode = 1 is already visited ✅
// BUT parent = 6, and 1 ≠ 6 → cycle found
// else if(adjacentNode != parent) → 1 ≠ 6 → return true
// This means:
// We reached 3 from 6
// 3 has an edge to 1
// But 1 is not the parent of 3 → it means there’s another way to reach 1, so there’s a cycle.