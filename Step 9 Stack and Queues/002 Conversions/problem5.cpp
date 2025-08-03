// converting a postfix expression to prefix expression

#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string expression) {
    stack<string> st;

    for (int i = 0; i < expression.length(); i++) {
        char currentPointer = expression[i];

        // If the character is an operand (letter or digit)
        if (isalnum(currentPointer)) {
            // Push the operand as a string onto the stack
            st.push(string(1, currentPointer));
        } 
        else {
            // Pop the top two elements from the stack for the operator
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            // Form a new prefix expression by combining the operator and operands
            string newElement = currentPointer + top2 + top1;
            
            // Push the new expression back onto the stack
            st.push(newElement);
        }
    }

    // The final element in the stack will be the complete prefix expression
    return st.top();
}

int main() {
    string postfixExpression = "AB-DE+F*/";
    cout << "Postfix expression: " << postfixExpression << endl;

    string PrefixExpression = postfixToPrefix(postfixExpression);
    cout << "Prefix expression: " << PrefixExpression << endl;

    return 0;
}

// TC: O(N) + O(N) => for combining two strings and for running a for loop
// SC: O(N)