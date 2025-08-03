// Problem 10:- Longest Consecutive sequence in an array
// Ex: {102,4,100,1,101,3,2,1,1} ==> Ans: {1,2,3,4}

// Brute Force Method:-
// Here do linear search for each and every element whether (i+1)th element is present or not
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    int longest = 1;
    
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}


// Better Solution:-
// First here we have ‘lastSmaller’ → (to store the last included element of the current sequence), 
//                    ‘cnt’ → (to store the length of the current sequence), 
//                    ‘longest’ → (to store the maximum length).
// So at every step, check whether the previous small element is present, if present then increase the cnt value and update the lastSmaller to that element, if not present start the cnt variable with 1 and update the lastSmaller
// TC:- O(NlogN) + O(N)
// SC:- O(N)
#include<bits/stdc++.h>
using namespace std;

void longest(vector<int>& arr,int n){
    sort(arr.begin(),arr.end());
    int lastSmaller=INT_MIN;
    int count=0;
    int longest=1;

    for(int i=0;i<n;i++){
        if(arr[i]-1 == lastSmaller){
            count+=1;
            lastSmaller=arr[i];
        }
        else if(arr[i]!=lastSmaller){
            count=1;
            lastSmaller=arr[i];
        }
        longest=max(longest,count);
    }

    cout<<"Longest consecutive sequence is: "<<longest<<endl;
}

int main(){
    int n=9;
    vector<int> arr={102,4,100,1,101,3,2,1,1};
    // 1, 1, 1, 2, 3, 4, 100, 101, 102;

    longest(arr,n);

    return 0;
}


// Optimal Method:-
// Here take a unordered set and insert all the elements,now take the first element and check whether it's previous element is present in set, if present leave it and increase the value of i, if not present then it means that it is the starting point of longest sequence, now find whether the remaining elements are present from the element which gave you false during a previous check
// TC:- O(N)+O(2N) --> O(3N)
//  O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
// SC:- O(N)
// The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations. 
// If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2). And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).
#include<bits/stdc++.h>
using namespace std;

void sequence(vector<int>& arr,int n){
    unordered_set<int> st;
    int longest=1;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int count=1;
            int element=it;
            while(st.find(it+1)!=st.end()){
                it=it+1;
                count++;
            }
            longest=max(longest,count);
        }
    }

    cout<<"Longest consecutive sequence is: "<<longest<<endl;

}

int main(){
    int n=9;
    vector<int> arr={102,4,100,1,101,3,2,1,1};

    sequence(arr,n);

    return 0;
}