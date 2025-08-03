//Problem 2:-MAJORITY ELEMENT(>N/2 TIMES)
//You will be given an array with numbers having multiple occurences
//EX:- arr[]=[2,2,3,3,1,2,2] i.e here N=7 so the majority element should have occurences greater than N/2 i.e should have more than 3 occurences

//Brute Force Method:-
//Here we take each and every element and and find the number of times it occurs in the entire array and if we find anyone, then return that element
//TC:- O(N^2)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void majorityElement(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if(count>n/2){
            cout<<arr[i];
        }
    }
}

int main(){
    int n=7;
    vector<int> arr={2,2,3,3,1,2,2};

    majorityElement(arr,n);

    return 0;
}

//Better Solution:-
//Here we use hashing to store the count of the element that is re-occuring
//TC:- if used ordered map - O(N*logN) + O(N), if unorederd map - O(N*1) - in best and avg case and O(N^2) for the worst case 
//SC:- O(N) - at the worst case
#include<bits/stdc++.h>
using namespace std;

void majorityElement(vector<int>& arr,int n){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second>(n/2)){
            cout<<it.first<<endl;
        }
    }
}

int main(){
    int n=7;
    vector<int> arr={2,2,3,3,1,2,2};

    majorityElement(arr,n);

    return 0;
}


//Optimal Method:-
//Moore's Voting Algorithm
//Here first take the starting element and keep a counter variable which is used for checking the occurences in a particular section of the array, so first the count will be zero, so assign the count to one and the element to some variable, then if that element occurs increase the count, if not decrease the count, and atlast the element with some count value will be the majority element
//i.e the intution behind the algorithm is that if the count becomes zero at some point of the array, it means that it is not satisfying the main theme of the problem i.e majority element is present greater than N/2 times
//And after this if acutally the majority element is present then that's answer, to verify whether it is really the required answer once again iterate through the array and find the count of majority element, and if we get the desired result submit the code
//TC:- O(N)+O(N)
//SC:- O(1)
#include<bits/stdc++.h>
using namespace std;

void majorityElement(vector<int>& arr,int n){
    // vector<int> arr={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int counter=0;
    int element;
    for(int i=0;i<n;i++){
        if(counter==0){
            counter=1;
            element=arr[i];
        }
        else if(arr[i]==element){
            counter++;
        }
        else{
            counter--;
        }
    }

    int counter2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            counter2++;
        }
    }

    if(counter2>(n/2)){
        cout<<element;
    }
}

int main(){
    int n=16;
    vector<int> arr={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};

    majorityElement(arr,n);

    return 0;
}