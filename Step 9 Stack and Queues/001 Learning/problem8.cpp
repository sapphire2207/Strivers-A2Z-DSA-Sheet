// Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
// [
// [ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]
// ]
// Result: [null, null, null, null, -3, null, 0, -2]
// Explanation: 
// stack < long long > st
// st.push(-2); Push element in stack
// st.push(0); Push element in stack
// st.push(-3); Push element in stack
// st.getMin(); Get minimum element fromstack
// st.pop(); Pop the topmost element
// st.top(); Top element is 0
// st.getMin(); Minimum element is -2

// Solution 1: Using pairs to store the value and minimum element till now. 
// Approach: The first element in the pair will store the value and the second element will store the minimum element till now.
// When the first push operation comes in we will push the value and store it as minimum itself in the pair. 
// In the second push operation, we will check if the top element’s minimum is less than the new value. If it is then we will push the value with minimum as the previous top’s minimum. To get the getMin element to take the top’s second element.
// Time Complexity: O(1)
// Space Complexity: O(2N)
#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<pair<int,int>> st;

    public:
    void push(int x){
        if(st.empty()){
            st.push({x,x});
        }
        else{
            st.push({x, min(x, st.top().second)});
        }
    }

    void getMin(){
        st.top().second;
    }

    void top(){
        st.top().first;
    }

    void pop(){
        st.pop();
    }
};

// Solution 2:

// Approach: 
// Let’s take a variable that stores the minimum number. So whenever a push operation comes in just take that number put it in the stack and update the variable to the number.
// Push operation:
// Now if there is a push operation just check whether that number is less than the min number. If it is smaller than min we will push a modified value which is a push(2 * Val - min) into the stack and will update min to the value of the original number. If it’s not then we will just push it as it is.
// getMin() operation:
// We will just return the value of min.
// Top operation:
// While returning the top value we know that it is a modified value. We will check if the top value is lesser than min, If it is then we will return the min as the top value.
// Pop operation:
// While making pop we will check if the top value is lesser than min, If it is then we must update our min to its previous value. In order to do that min = (2 * min) - (modified value) and we will pop the element.

// Time Complexity: O(1)
// Space Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

class MinStackTwo{
    stack < long long > st;
    long long mini;

    public:
    void push(int x){
        if(st.empty()){
            mini = x;
            st.push(x);
        }
        else{
            if(x < mini){
                st.push(2*x - mini);
                mini = x;
            }
            else{
                st.push(x);
            }
        }
    }

    void pop(){
        if(st.empty()){
            return;
        }
        long long x = st.top();
        st.pop();
        // If x < mini means the value has been modified then we need to store the previous mini back again...
        if(x < mini){
            mini = 2*mini - x;
        }
    }

    int top(){
        if(st.empty()){
            return 0;
        }
        long long x = st.top();
        // If mini < x means the value hasn't been modified....
        if(mini < x) return x;
        return mini;
    }
    int getMin() {
        return mini;
    }
};