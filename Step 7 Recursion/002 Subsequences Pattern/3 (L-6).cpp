// Print all the possible subsequences of the String (Lecture - 6)

// Examples:
// Example 1:
// Input: str = "abc"
// Output: a ab abc ac b bc c
// Explanation: Printing all the 7 subsequence for the string "abc".

// Example 2:
// Input: str = "aa"
// Output: a a aa 
// Explanation: Printing all the 3 subsequences for the string "aa"

// Solution 1: Using recursion(Backtracking)
// Intuition: Since we are generating subsets two cases will be possible, either you can pick the character or you cannot pick the character and move to the next character.

// Approach:
// Maintain a temp string (say f),which is empty initally.
// Now you have two options,either you can pick the character or not pick the character and move to the next index.
// Firstly we pick the character at ith index and then move to the next index.(f + s[i])
// If the base condition is hit,i.e i==s.length() ,then we print the temp string and return.
// Now while backtracking we have to pop the last character since now we have to implement the non-pick condition and then move to next index.

#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}

// Output:
// All possible subsequences are:
// abc ab ac a bc b c

// Time Complexity: O(2^n)
// Space Complexity: O(n), recursion stack.