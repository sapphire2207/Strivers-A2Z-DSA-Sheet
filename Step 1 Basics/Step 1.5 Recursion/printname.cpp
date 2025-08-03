//TO PRINT NAME 'N' TIMES USING RECURSION

// What is Stack Overflow in Recursion?
// Whenever recursion calls are executed, they’re simultaneously stored in a recursion stack where they wait for the completion of the recursive function. A recursive function can only be completed if a base condition is fulfilled and the control returns to the parent function. 
// But, when there is no base condition given for a particular recursive function, it gets called indefinitely which results in a Stack Overflow i.e, exceeding the memory limit of the recursion stack and hence the program terminates giving a Segmentation Fault error. 


//TC - O(N) since the function is being called n times
//SC - O(N)
#include<bits/stdc++.h>
using namespace std;

void nameNtimes(int i,int n){
    if(i>n) return;
    cout<<"Coding Ninjas"<<" ";
    nameNtimes(i+1,n);
}

int main(){
    int n;
    cin>>n;

    nameNtimes(1,n);
}

//CODE SUBMISSION
// void nameNtimes(int i,int n,vector<string>& ans){
// 	if(i>n) return;
// 	ans.push_back("Coding Ninjas");
// 	nameNtimes(i+1,n,ans);
// }

// vector<string> printNTimes(int n) {
// 	vector<string> ans;
// 	nameNtimes(1,n,ans);
// 	return ans;
// }

