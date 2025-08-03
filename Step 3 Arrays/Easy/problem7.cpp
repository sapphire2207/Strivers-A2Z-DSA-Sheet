//Problem 7:- Moving the Zeroes to the end of the array

//Brute Force Method:-
// First store all the non-zero elements in a temporary array
// Then add the elements of the temporary array to the new array
// Then assign the remaining portion of the array to zeroes

//TC:- O(N) + O(x) + O(N-x) -> O(2N) where x is the number of non-zeores
//Sc:- O(x) and in the worst case it may be O(N)
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int arr[],int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }


    int nonZeroes=temp.size();
    for(int i=0;i<nonZeroes;i++){
        arr[i]=temp[i];
    }

    for(int i=nonZeroes;i<n;i++){
        arr[i]=0;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    moveZeroes(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//CODE SUBMISSION:-
vector<int> moveZeros(int n, vector<int> a) {
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            temp.push_back(a[i]);
        }
    }

    int nonZeroes=temp.size();
    for(int i=0;i<nonZeroes;i++){
        a[i]=temp[i];
    }

    for(int i=nonZeroes;i<n;i++){
        a[i]=0;
    }

    return a;
}


//Optimised Method:- Two Pointer Approach
//First iterate through the entire loop to find out the first zero guy
//Then Iterate from the next element and till the last guy.
//If you find any non-zero guy replace it with the first zero guy you got,and move forward your zeroth guy's position.....
//TC:- O(x) it is the position where the 0th guy is present + O(N-x) -> O(N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }

    if(j==-1) return;

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;        
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    moveZeroes(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
