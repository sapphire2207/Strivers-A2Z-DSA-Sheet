// Problem 7:- 
// Variety 1: when postives = negatives
// Rearrange the elements by sign, you will be given an array of equal +ve and -ve elements, so the aim is to make an array of alternating postive and negative numbers

// Brute Force Method:- 
// Iterate through all the elements of the array, if the element is positive then add it into the positive array, or else add it into the negative array, after that place them back into the original array with help of index's logic
// TC:- O(N) + O(N/2) --> for iterating and for rearranging
// SC:- O(N/2 + N/2) ==> O(N)
#include<bits/stdc++.h>
using namespace std;

void arrange(vector<int>& arr, int n){
    vector<int> positive;
    vector<int> negative;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }

    for(int i=0;i<n/2;i++){
        arr[2*i]=positive[i];
        arr[2*i+1]=negative[i];
    }  

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }  
}

int main(){
    int n=4;
    vector<int> arr={1,2,-4,-5};

    arrange(arr,n);

    return 0;
}

// Optimal Method:- 
// Here we are just iterating through each and every element of the array,the positive index is zero and negative index is 1, and then if the number is positive then store it in the ans[positive] and move the positive index 2 places ahead, if number is negative then store it in the ans[negative] and move the negative index 2 places ahead
// TC:- O(N)
// SC:- O(N)
#include<bits/stdc++.h>
using namespace std;
    // vector<int> arr={1,2,-4,-5};
void rearrange(vector<int>& arr, int n){
    vector<int> ans;
    int positive=0;
    int negative=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negative]=arr[i];
            negative+=2;
        }
        else{
            ans[positive]=arr[i];
            positive+=2;
        }
    }

    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main(){
    int n=4;
    vector<int> arr={1,2,-4,-5};

    rearrange(arr,n);
}

// Variety 2:- When the number of positives and negatives are not equal in number
// First iterate through the array and store the positives and negatives in different arrays, and now if positives>negatives, then iterate till the number of negatives in the arrays and store the positives and negatives, and from the twice the count of negatives to last element of the array stire the remaining positives and vice-versa for positives<negatives
// TC:- O(N) --> for iterating + O(min(pos,neg)) ==> (i) here positives or negatives may be zero, so O(N), (ii) if positives and negatives are equal, then O(N/2) + O(leftovers) ==> (i) here if positives and negatives are zero the leftovers will be O(N), (ii) if positives and negatives are equal then leftovers will be O(0) ====> Last two complexities boils to O(N), hence therfore O(2N)
// SC:- O(N)
#include<bits/stdc++.h>
using namespace std;

void arranging(vector<int>& arr,int n){
    vector<int> positivee;
    vector<int> negativee;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            positivee.push_back(arr[i]);
        }
        else{
            negativee.push_back(arr[i]);
        }
    }

    if(positivee.size()>negativee.size()){
        for(int i=0;i<negativee.size();i++){
            arr[2*i]=positivee[i];
            arr[2*i+1]=negativee[i];
        }

        int index1=negativee.size()*2;
        for(int i=negativee.size();i<positivee.size();i++){
            arr[index1]=positivee[i];
            index1++;
        }
    }else{
        for(int i=0;i<positivee.size();i++){
            arr[2*i]=positivee[i];
            arr[2*i+1]=negativee[i];
        }

        int index2=positivee.size()*2;
        for(int i=positivee.size();i<positivee.size();i++){
            arr[index2]=negativee[i];
            index2++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n=6;
    vector<int> arr={-1,2,3,4,-3,1};

    arranging(arr,n);
}
