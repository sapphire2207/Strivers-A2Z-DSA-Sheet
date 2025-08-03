//PRINT NUMBERs FROM N TO 1 USING RECURSION
//TC - O(N) //SC - O(N)
#include<bits/stdc++.h>
using namespace std;
void nToOne(int i){
    if(i<1) return;
    cout<<i<<endl;
    nToOne(i-1);
}

int main(){
    int n;
    cin>>n;

    nToOne(n);

    return 0;
}
//CODE SUBMISSION
// void nToOne(int i,vector<int>&arr){
//     if(i<1) return;
//     arr.push_back(i);
//     nToOne(i-1,arr);
// }

// vector<int> printNos(int x) {
//     vector<int> arr;

//     nToOne(x,arr);

//     return arr;
// }

//USING BACKTRACKING
#include<bits/stdc++.h>
using namespace std;
void nToOne(int i,int n){
    if(i>n) return;
    nToOne(i+1,n);
    cout<<i<<endl;
}
int main(){
    int n;
    cin>>n;

    nToOne(1,n);

    return 0;
}
// // CODE SUBMISSION
// void nToOne(int i,int n,vector<int>&arr){
//     if(i>n) return;
//     nToOne(i+1,n,arr);
//     arr.push_back(i);
// }

// vector<int> printNos(int x) {
//     vector<int> arr;
//     nToOne(1,x,arr);
//     return arr;
// }

