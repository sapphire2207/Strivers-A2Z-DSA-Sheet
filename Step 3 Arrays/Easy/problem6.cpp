//Problem 6:- LEFT ROTATE THE ARRAY BY D PLACES

//Ex:- 1 2 3 4 5 6 7 (The size of the array is 7)
//Now rotate the array by 3 places -> 4 5 6 7 1 2 3
//Now rotate the array by 16 places -> for every 7 places the array comes to it's normal position, similarly for the 14th time it comes back to original position, So now we should rotate it by 2 places more. -> 3 4 5 6 7 1 2
//So when D is greater than the size of the array, therfore we should rotate D%N places

//Brute Force Method:-
//So first we are placing the D elements into a new array, then using indexing we move the further elements to the start of that array, after that place back the the D elements back into the array..
//SC: O(D)
#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[],int n,int d){
    d=d%n;

    //TC:- O(d)
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    
    //TC: O(n-d)
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    //TC:- O(d) -> Therfore O(N+d)
    //Method 1:
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
    
    // //Method 2:
    // int j=0;
    // for(int i=n-d;i<n;i++){
    //     arr[i]=temp[j];
    //     j++;
    // }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cin>>d;

    rotateArray(arr,n,d);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//CODE SUBMISSION:-
vector<int> rotateArray(vector<int>arr, int k) {

    k=k%arr.size();
    vector<int> temp;

    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }

    for(int i=k;i<arr.size();i++){
        arr[i-k]=arr[i];
    }

    for(int i=arr.size()-k;i<arr.size();i++){
        arr[i]=temp[i-(arr.size()-k)];
    }

    return arr;
}


//Optimal Method:-
//Fisrt reverse the part of the array which is having the D elements
//Then reverse the remaining part of the array
//So you get your desired array by now reversing the above entire array

//TC:- O(d)+O(n-d)+O(n) -> O(2n);
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int start,int end){
    if(start>=end) return;
    swap(arr[start],arr[end]);
    reverseArray(arr,start+1,end-1);
}

void rotateArray(int arr[],int n,int k){

    //Method 1:-
    // reverse(arr,arr+k);
    // reverse(arr+k,arr+n);
    // reverse(arr,arr+n);

    //Method 2:-
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,n-1);
    reverseArray(arr,0,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    rotateArray(arr,n,k);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//CODE SUBMISSION:-
#include<bits/stdc++.h>
void reverseArray(vector<int>&arr,int start,int end){
    if(start>=end) return;
    swap(arr[start],arr[end]);
    reverseArray(arr,start+1,end-1);
}
vector<int> rotateArray(vector<int>arr, int k) {
    
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,arr.size()-1);
    reverseArray(arr,0,arr.size()-1);

    return arr;
}

//***Solve if it is right rotating the array by D places***//
