//PRINT NUMBERS FROM 1 TO N USING RECURSION
//TC - O(N) //SC - O(N)
#include<bits/stdc++.h>
using namespace std;

void oneToN(int i,int n){
    if(i>n) return;
    cout<<i<<endl;;
    oneToN(i+1,n);
}

int main(){
    int n;
    cin>>n;

    oneToN(1,n);
}

//CODE SUBMISSION
// void oneToN(int i,int x,vector<int>&arr){
//     if(i>x) return;
//     arr.push_back(i);
//     oneToN(i+1,x,arr);
// }
// vector<int> printNos(int x) {
//     vector<int> arr;
//     oneToN(1,x,arr);

//     return arr;
// }

//RECUSRION USING BACKTRACKING
#include<bits/stdc++.h>
using namespace std;

void onetoN(int i){
    if(i<1) return;
    onetoN(i-1);
    cout<<i<<endl;
}

int main(){
    int n;
    cin>>n;
    onetoN(n);
    return 0;
}

//CODESUBMISSION
// void oneToN(int i,vector<int>&arr){
//     if(i<1) return;
//     oneToN(i-1,arr);
//     arr.push_back(i);

// }

// vector<int> printNos(int x) {
//     vector<int> arr;
//     oneToN(x,arr);

//     return arr;
// }