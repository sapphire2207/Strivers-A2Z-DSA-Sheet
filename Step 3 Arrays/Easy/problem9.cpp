//Problem 9:- TWO SORTED ARRAYS ARE GIVEN TO YOU, FIND THE UNION ARRAY

//Method 1:-Brute Force
//First take a set and iterate through the first array and insert elements according to it
//Also iterate through the second array and insert elements to the set
//Now in a new array named 'union' add all the elements of the set
//TC:- O(n1logn) -> where n is the size of the set + O(n2logn) + O(n1+n2) -> because in the worst case all the elements are different ---> O(n1logn)+ O(n2logn) + O(n1+n2)
//SC:- O(n1) + O(n2) -> worst case in inserting the elements into the set + O(n1+n2) -> inserting them into the union array -->These are the extra spaces used in the algorithm
#include <bits/stdc++.h>
using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

int main(){
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}

//CODE SUBMISSION:-
#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
   int n1=a.size();
   int n2=b.size();

   set<int> st;
   for(int i=0;i<n1;i++){
       st.insert(a[i]);
   }
   for(int i=0;i<n2;i++){
       st.insert(b[i]);
   }

   vector<int> temp;
   for (auto it : st) {
       temp.push_back(it);
   }
   return temp;
}

//Method 2:-Optimal Approach
//First take a pointer at the first element of the first array as i
//Also take a pointer at the first element of the second array as j
//Now if the first element of the first array is less than or equal to the first element of the second array then take the element from the first array and move the i pointer
//Else take the element from the second array and move the j pointer
//But remember that while taking the element, the element must not be equal to the previous element of the submitting array
//TC:- O(N1+n2) we are almost iterating through both the arrays
//SC:- O(N1+N2) we are using an extra array of max size of both the arrays
#include<bits/stdc++.h>
using namespace std;

void ans(int first[],int n1,int second[],int n2){
    vector<int> unionArr;

    int i=0;
    int j=0;

    while(i<n1 && j<n2){
        if(first[i]<=second[j]){
            if(unionArr.size()==0 || unionArr.back() != first[i]){
                unionArr.push_back(first[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=second[j]){
                unionArr.push_back(second[j]);
            }
            j++;
        }
    } 

    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=second[j]){
                unionArr.push_back(second[j]);
        }
        j++;
    }

    while(i<n1){
       if(unionArr.size()==0 || unionArr.back()!=first[i]){
                unionArr.push_back(first[i]);
        }
        i++; 
    }


    for(auto it:unionArr){
        cout<<it<<" ";
    }
}

int main(){

    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    int first[n1];
    int second[n2];

    for(int i=0;i<n1;i++){
        cin>>first[i];
    }

    cout<<"First Array Filled"<<endl;

    for(int i=0;i<n2;i++){
        cin>>second[i];
    }

    ans(first,n1,second,n2);

    return 0;
}

//CODE SUBMISSION:-
#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
   int n1=a.size();
   int n2=b.size();

   int i=0;
   int j=0;

   vector<int> unionArr;
   while(i<n1 && j<n2){
       if(a[i]<=b[j]){
           if(unionArr.size()==0 || unionArr.back()!=a[i]){
               unionArr.push_back(a[i]);
           }
           i++;
       }
       else{
           if(unionArr.size()==0 || unionArr.back()!=b[j]){
               unionArr.push_back(b[j]);
           }
           j++;
       }
   }

   while(j<n2){
       if(unionArr.size()==0 || unionArr.back()!=b[j]){
               unionArr.push_back(b[j]);
        }
        j++;
   }

   while(i<n1){
       if(unionArr.size()==0 || unionArr.back()!=a[i]){
               unionArr.push_back(a[i]);
        }
        i++;
   }

   return unionArr;
}



//INTERSECTION OF TWO SORTED ARRAYS
//There may be duplicate elements
//Linear searching every element by creating a visited array
//Brute Force Method:-
//TC:- O(N1*N2)
//SC:- O(N2)
#include<stdio.h>
using namespace std;

void intersection(int n1,int n2, int a[],int b[]){
    vector<int> ans;
    int vis[n2]={0};
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j] && vis[j]==0){
                ans.push_back(a[i]);
                vis[j]++;
                break;
            }
            else if(b[j]>a[i]){
                break;
            }
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main(){
    int n1,n2;
    cin>>n1>>n2;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }

    intersection(n1,n2,a,b);

    return 0;
}

//Optimal Approach:-
//Two pointer approach
//TC:- In the worst case it may be O(m+n) where the pointers are alternatingly moving in both the arrays
//SC:- No extra space is used, therefore --> O(1)
#include<bits/stdc++.h>
using namespace std;

void intersect(int m,int n, int a[],int b[]){
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<j){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main(){
    int m,n;
    cin>>m>>n;

    int a[m];
    int b[n];

    for(int i=0;i<m;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    intersect(m,n,a,b);

    return 0;
}