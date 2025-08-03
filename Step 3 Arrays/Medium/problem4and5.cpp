// Problem 4 and 5 : You will be given an array, you need to find out the maximum sub-array sum, and the required sub-array must contain atleast one element

// EX: arr={-2,-3,4,-1,-2,1,5,-3} ==> Ans = 7

// Brute Force Method:-
// Generate all the sub-arrays and find the sum of each sub-array, and after finding the sum of each sub-array, keep on updating the maximum sum
// TC:- O(N^3)
// SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void maxSum(vector<int>& arr,int n){
    int sum;
    int mxx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
                mxx=max(sum,mxx);
            }
        }
    }

    cout<<"Maximum Sum is "<<mxx<<endl;
}

int main(){
    int n=8;
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};

    maxSum(arr,n);

    return 0;
}

// Better Solution:-
// In the above solution we are running a inner loop which makes us to iterate again and again, but we can reduce the complexity by just adding the sum of each element to a variable without running a loop
// TC:- O(N^2)
// SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void maxSum(vector<int>& arr,int n){
    int sum;
    int mxx=INT_MIN;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            mxx=max(sum,mxx);
        }
    }

    cout<<"Maximum Sum is "<<mxx<<endl;
}

int main(){
    int n=8;
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};

    maxSum(arr,n);

    return 0;
}

// Optimal Method:-
// Kadane's Algo:
// In this approach, we keep on iterating through each element and maintain a sum variable, now if the value of sum is negative, it will be of no use bcz it decreases the maximum sum, so re-intialize it to zero when it does happen, and when the sum is positive update the maximum variable, and now if any negative number occurs with a postive number or if the sum is positive even though including the negative number, take it into consideration, bcz it may in the future help in increasing the sum.
// TC:- O(N);
// SC:- O(1);
#include<bits/stdc++.h>
using namespace std;
    // vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
void maxiSum(vector<int>& arr, int n){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;
        }
        // sum = max(sum, maxi);

        if(sum<0){
            sum=0;
        }
    }

    if(maxi<0){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Maximum sum is: "<<maxi<<endl;
    }
}

int main(){
    int n=8;
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};

    maxiSum(arr,n);
}

// FOLLOW-UP QUESTION:- To print the maximum Sub-array
// Here maintain variables called start, ansStart, ansEnd, so we can analyze that whenever the sum is zero we update the start to 'i', and the ansStart will be 'i' in the if condition, and ansEnd will be the 'i' index bcz we are in the if loop, which will automatically contain the position
// TC:- O(N)
// SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void maxiSum(vector<int>& arr, int n){
    int sum=0;
    int maxi=INT_MIN;
    int start;
    int ansStart=-1;
    int ansEnd=-1;
    for(int i=0;i<n;i++){

        if(sum==0){
            start=i;
        }
        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }

        if(sum<0){
            sum=0;
        }
    }

    if(maxi<0){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Maximum sum is: "<<maxi<<endl;
    }

    cout<<"Sub-array is: [";
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]";
}

int main(){
    int n=8;
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};

    maxiSum(arr,n);
}