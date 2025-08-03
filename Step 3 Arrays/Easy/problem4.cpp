//Problem 4:- Remove Duplicates from a Sorted Array

//Brute Force Method:-duplicate
// Intuition: We have to think of a data structure that does not store  elements. So can we use a Hash set? Yes! We can. As we know HashSet only stores unique elements.
//TC:- Set data structure takes O(NlogN) + O(N)
//SC:- O(N)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    int index=0;
    for(auto it:st){
        arr[index]=it;
        index++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Number of Unique Elements"<<index+1;
}

//Optimised Method:-
// Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don't get a number arr[j] which is different from arr[i]. As we get a unique number we will increase the i pointer and update its value by arr[j]. 
// Two pointer approach
// TC:- O(N)
// SC:- O(1)
#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[j] != arr[i]) {
      arr[i+1] = arr[j];
      i++;
    }   
  } 
  return i + 1; 
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

//CODE SUBMISSION:-
int removeDuplicates(vector<int> &arr, int n) {
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[j]!=arr[i]){
			arr[i+1]=arr[j];
			i++;
		}
	}
	return i+1;
}