// Sort a Stack using Recursion

// Given a stack, the task is to sort it using recursion.

// Example: 
// Input: [3 2 1]
// Output: [3 2 1]
// Explanation: The given stack is sorted know 3 > 2 > 1

// Input: [11 2 32 3 41]
// Output: [41 32 11 3 2]

// Approach:
// First we have to repeatedly pop the elements by storing the top_element at each function call.
// When the stack becomes empty, we call the sortedInsert() which takes the current stack and a top_element to insert the element into stack.
// The sortedInsert() ensures that the element is placed in the correct position in the already sorted stack.
// How does sortedInsert() Work?
// This function again uses recursion.
// If stack is empty or top of the stack is smaller, we push the item at the top
// Else we remove the top item and call sortedInsert recursively for the remaining stack and current item. This ensures that all greater values are held in the function call stack.
// We finally push the removed the top item back into the stack. This moves all the items held in function call stack into the given stack.
// Time Complexity: O(n^2). 
// For each of the n recursive calls in sortStack, a call to sortedInsert is made.
// In the worst case, sortedInsert may go through almost all elements below the current element (i.e., O(n) in the worst case for each insert) => O(N^2)
// Auxiliary Space: O(n) due to call stack and temporary stack.

#include<bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &st,int element){
    if(st.empty() || element > st.top())
        st.push(element);
    else{
        int top_element = st.top();
        st.pop();
        sortedInsert(st,element);
        st.push(top_element);
    }
}
void sortStack(stack<int> &st){
    if(!st.empty()){
        int top_element = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st,top_element);
    }
}
int main(){
    stack<int> st;
    int n;
    cin>>n;
    while (n--){
        int x;
        cin>>x;
        st.push(x);
    }
    sortStack(st);
    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout<<top<<endl;
    }
    return 0;
}