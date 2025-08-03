// Converting a decimal number to binary number

#include<bits/stdc++.h>
using namespace std;

// TC: O(log N base = 2)
// SC: O(log N base = 2)
void reverseString(int i,string &answer, int n){
    if(i>=answer.size()/2) return;
    swap(answer[i],answer[n-i-1]);
    reverseString(i+1,answer, n);
}

string convert2Binary(int number){
    string result = "";
    while(number != 1){
        if(number % 2 == 1){
            result = result + "1";
        }
        else{
            result = result + "0";
        }
        number = number / 2;
    }
    reverseString(0,result, result.size());
    return result;
}


int main(){

}