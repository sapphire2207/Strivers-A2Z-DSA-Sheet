//  Reverse a Stack using Recursion

// Write a program to reverse a stack using recursion, without using any loop.

// Example: 
// Input: elements present in stack from top to bottom 4 3 2 1
// Output: 1 2 3 4
// Input: elements present in stack from top to bottom 1 2 3
// Output: 3 2 1

// The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one at the bottom of the stack. 
// In the following illustration, we can see that we first make a recursive call so that all values are collected in the call stack, and then we insert at the bottom (using another recursive function - insertAtBottom()) so that while returning all items are pushed to stack in reverse order.

// Time Complexity: O(n2). 
// Auxiliary Space: O(n) use of Stack 

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.size() == 0) {
        s.push(x);
    } else {
        int a = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(a);
    }
}

void reverse(stack<int>& s) {
    if (s.size() > 0) {
        int x = s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s, x);
    }
}

int main() {
    stack<int> s;

    // Pushing elements to the stack: 4 3 2 1 (bottom to top)
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Reversing the stack
    reverse(s);

 
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}