// Converting an infix to postfix expression
// Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression.

// Example 1:
// Input: a+b*(c^d-e)
// Output: abcd^e-*+


// Approach: To convert Infix expression to Postfix
// 1. Scan the infix expression from left to right. 
// 2. If the scanned character is an operand, Print it. 
// 3. Else, 
// If the precedence of the scanned operator is greater than the precedence of the operator in the stack or the stack is empty or the stack contains a ‘(‘, push the character into the stack. 
// Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. 
// 4. If the scanned character is an ‘(‘, push it into the stack. 
// 5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
// 6. Repeat steps 2-5 until the entire infix expression is scanned. 
// 7. Print the output.
// 8. Pop and print the output from the stack until it is not empty.


#include<bits/stdc++.h>
using namespace std;

//Function to return precedence of operators
int precedence(char currentPointer){
    if(currentPointer == '^'){
        return 3;
    }
    else if (currentPointer == '/' || currentPointer == '*'){
        return 2;
    }
    else if (currentPointer == '+' || currentPointer == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infixToPostfix(string expression){
    stack<char> st;
    string result;
    for(int i = 0; i < expression.length(); i++){
        char currentPointer = expression[i];

        if((currentPointer >= 'a' && currentPointer <= 'z') || (currentPointer >= 'A' && currentPointer <= 'Z') || (currentPointer >= '0' && currentPointer <= '9')){
            result = result + currentPointer;
        }

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(currentPointer == '('){
            st.push('(');
        }

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(currentPointer == ')'){
            while(st.top() != '('){
                result = result + st.top();
                st.pop();
            }
            st.pop();
        }

        //If an operator is scanned
        else{
            while(!st.empty() && precedence(expression[i]) <= precedence(st.top())){
                result = result + st.top();
                st.pop();
            }
            st.push(currentPointer);
        }
    }

    // Pop all the remaining elements from the stack
    while(!st.empty()){
        result = result + st.top();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;
}

int main(){
    string expression = "a + b * (c ^ d - e)";
    cout << "Infix expression: " << expression << endl;
    infixToPostfix(expression);
    return 0;
}

// Time Complexity: O(N) + O(N)
// Space Complexity: O(N) for using the stack