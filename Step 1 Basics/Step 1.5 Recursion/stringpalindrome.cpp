// TO CHECK WHETHER GIVEN STRING IS A PALINDROME

// Recursive Method:-
// In this approach, we check the string using functional recursion where firstly, the letters on the two ends of the string (start, end) are compared to see if they’re the same or not.
// If they’re the same then we simply call recursion for the next elements (start+1, end-1) and so on until the start becomes greater than or equal to the end. 
// If at any point the start and the end differ, we return false stating that the string is not a palindrome.
// Otherwise, if the base condition is reached, then the string is obviously a palindrome and we return true.

// TC - O(N) {Precisely, O(N/2) as we compare the elements N/2 times and swap them}. 
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;
bool stringisPalindrome(int i,string &s){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    stringisPalindrome(i+1,s);
}

int main(){
    string s;
    cin>>s;

    bool ans=stringisPalindrome(0,s);
    return 0;
}

//CODE SUBMISSION:-
// bool palindrome(int i,string& str){
//     if(i>=str.size()/2) return true;
//     if(str[i]!=str[str.size()-i-1]) return false;
//     palindrome(i+1,str);
// }

// bool isPalindrome(string& str) {
//     bool ans=palindrome(0,str);
//     return ans;
// }