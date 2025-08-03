// Converting a prefix to postfix


#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string expression) {
    stack<string> st;

    for (int i = expression.length() - 1; i >= 0; i--) {
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

            // Form a new post expression by combining the operator and operands
            string newElement = top1 + top2 + currentPointer;
            
            // Push the new expression back onto the stack
            st.push(newElement);
        }
    }

    // The final element in the stack will be the complete post expression
    return st.top();
}

int main() {
    string prefixExpression = "/-AB*+DEF";
    cout << "Prefix expression: " << prefixExpression << endl;

    string PostfixExpression = prefixToPostfix(prefixExpression);
    cout << "Postfix expression: " << PostfixExpression << endl;

    return 0;
}

// TC: O(N) + O(N) => for combining two strings and for running a for loop
// SC: O(N)