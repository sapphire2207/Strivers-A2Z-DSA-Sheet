// Converting an infix to prefix expression

// Example:
// Given: (A + B) * C - D  + F

// First reverse the expression....
// Then perform the algorithm (infix to postfix)...
// Reverse the expression again back

#include<bits/stdc++.h>
using namespace std;

string reverseString(int i,string &answer, int n){
    if(i>=answer.size()/2) return answer;
    if (answer[i] == '(') answer[i] = ')';
    else if (answer[i] == ')') answer[i] = '(';

    if (answer[n - i - 1] == '(') answer[n - i - 1] = ')';
    else if (answer[n - i - 1] == ')') answer[n - i - 1] = '(';

    swap(answer[i],answer[n-i-1]);
    return reverseString(i+1,answer, n);
}

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

void infixToPrefix(string expression){
    string reversedExpression = reverseString(0, expression, expression.length());

    stack<char> st;
    string result;

    for(int i = 0; i < reversedExpression.length(); i++){
        char currentPointer = reversedExpression[i];

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
            if(currentPointer == '^'){
                // You cannot store two powers in a stack
                while(!st.empty() && precedence(currentPointer) <= precedence(st.top())){
                    result += st.top();
                    st.pop();
                }
            }
            else{
                while (!st.empty() && precedence(currentPointer) < precedence(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(currentPointer);
        }
    }
    
    while(!st.empty()){
        result = result + st.top();
        st.pop();
    }

    string finalAnswer = reverseString(0, reversedExpression, reversedExpression.length());

    cout << "Prefix expression: " << finalAnswer << endl;
}

int main(){
    string expression = "(A + B) * C - D  + F";
    cout << "Infix expression: " << expression << endl;
    infixToPrefix(expression);
    return 0;
}

// TC: O(N/2) + O(N/2) + O(2N)
// SC: O(N)