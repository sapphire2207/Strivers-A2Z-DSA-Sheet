// Alien Dictionary - Topological Sort: G-26

// Problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order.

// Let’s consider the first example where N = 5, K = 4 and dict = {"baa", "abcd", "abca", "cab", "cad"}. So, here we need to find out the correct ordering of the first 4 letters of the alphabet(i.e. ‘a’, ‘b’, ‘c’, ‘d’). If we consider the first 2 words and try to figure out why “baa” appears before “abcd”, we can clearly observe that they are differentiated by the first letter i.e. ‘b’ and ‘a’. That is why, we can conclude that in the alien dictionary, ‘b’ appears before ‘a’( i.e. ‘b’ is smaller than ‘a’). We can correspond this differentiating factor to a directed graph like the following:
// Let’s understand why we need not check “baa” and “abca” (the 1st and the 3rd word) next:
// Until now, we have figured out why “baa” appears before “abcd”. So, by convention, if “abcd” is appearing before “abca” and “baa” is appearing before “abcd”, “baa” will obviously appear before “abca”. That is why we will check the pair of “abcd” and “abca” next rather than checking “baa” with any other words and this flow will be continued for the rest of the words.
// Note: Points to remember that we need not check every pair of words rather we will just check the consecutive pair of words in the dictionary. Comparing each pair of consecutive words in the dictionary, we can construct a directed graph like the following:
// Now, we have successfully reduced the problem to a known directed graph problem. If we look at the problem from the graph point of view, we just need to find out the linear ordering of the nodes of the directed graph. And we can do this easily using the topological sort algorithm which we have previously learned.

// To further simplify the problem, we will denote the alphabet with numbers like: ‘a’ with 0, ‘b’ with 1, ‘c’ with 2, and so on. For example, if the letter is ‘z’, we will denote it using 25. Finally, the directed graph will look like the following illustration:
// Note: The intuition is to check every consecutive pair of words and find out the differentiating factor. With these factors, we will form a directed graph, and the whole problem balls down to a topological sort of problem.
// Edge Case: The problem arises when the value of K becomes 5 and there is no word in the dictionary containing the letter ‘e’. In this case, we will add a separate node with the value ‘e’ in the graph and it will be considered a component of the directed graph like the following, and the same algorithm will work fine for multiple components.
// Note: If the value of K is greater than the number of unique characters appearing in the dictionary, then the extra characters will be considered the different components of the directed graph formed.

// The follow-up question for the interview:
// When is the ordering not possible?
// There are two such cases when ordering is not possible:
// If every character matches and the largest word appears before the shortest word: For example, if “abcd” appears before “abc”, we can say the ordering is not possible.
// If there exists a cyclic dependency between the characters: For example, in the dictionary: dict: {“abc”, “bat”, “ade”} there exists a cyclic dependency between ‘a’ and ‘b’ because the dictionary states ‘a’ < ‘b’ < ‘a’, which is not possible.

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// works for multiple components
private:
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
public:
	string findOrder(string dict[], int N, int K) {
		vector<int>adj[K];
		for (int i = 0; i < N - 1; i++) {
			string s1 = dict[i];
			string s2 = dict[i + 1];
			int len = min(s1.size(), s2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					break;
				}
			}
		}

		vector<int> topo = topoSort(K, adj);
		string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');
		}
		return ans;
	}
};

int main() {

	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}

// Output: b d a c 
// Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.
// Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency list used in the algorithm.