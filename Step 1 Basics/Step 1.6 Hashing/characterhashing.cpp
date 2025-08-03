//CHARACTER HASING:-

//BRUTE FORCE METHOD:-
//TC - If the number of queries is Q, the time complexity will be O(Q*N) where N = size of the string. 
#include<bits/stdc++.h>
using namespace std;

int queryCount(string s,char q,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]==q){
            count+=1;
        }
    }
    return count;
}
int main(){
    string s;
    cin>>s;

    char q;
    cin>>q;

    int appear=queryCount(s,q,s.size());
    cout<<appear;
}

//OPTIMISED METHOD:-
//CASE 1:-
//TC - O(String Size) + O(queries)
//SC - O(26)
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    //precompute:
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}

//CASE 2:-
//TC - O(String Size) + O(queries)
//SC - O(256)
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    //precompute:
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c] << endl;
    }
    return 0;
}
