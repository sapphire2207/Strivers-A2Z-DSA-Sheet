//FINDING FACTORIAL OF A GIVEN NUMBER

//METHOD 1:- Using a for loop
// Approach:
// Since the factorial of X  will be the product of the number itself and all its preceding numbers we can run loop i, from 1 to X. In every iteration current i, is multiplied with the product so far.  

//TC - O(N) //SC - O(1)
#include <iostream>
using namespace std;
int factorial(int n) {
   int ans = 1;
   for (int i = 1; i <=n; i++) {
      ans = ans * i;
   }
   return ans;
}
int main() {
   int n;
   cin>>n;
   int result = factorial(n);
   cout << "The factorial of " <<n<< " is " << result;
}

//METHOD 2:-Functional way
// Approach:
// The Factorial of a number N can be calculated by multiplying all the natural numbers till the number N. Through this approach, we can visualize the factorial of n natural numbers in the following way as shown below:
// factorial(N) = N * factorial(N-1);
// The Factorial of N natural numbers is the Nth integer multiplied by the Factorial of (N-1) natural numbers. The base case can be visualized as if n decreases to 0, then we return 1 because the factorial of 0 is 1 only. Here, we’ve just broken the problem into 2 subparts and the answers of both would be multiplied together and stored in the factorial(n) function which would then be printed at last.

// TC - O(N)
// SC - O(N) - In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space
#include<bits/stdc++.h>
using namespace std;

int factoriall(int n){
    if(n==0) return 1;
    return n*factoriall(n-1);
}

int main(){
    int n;
    cin>>n;

    int ans=factoriall(n);
    cout<<ans;
    return 0;
}

//METHOD 3.1 Parameterised way
// TC - O(N)
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void factoriall(int fact,int i){
    if(i==0){
        cout<<fact;
        return;
    }
    factoriall(fact*i,i-1);
}

int main(){
    int n;
    cin>>n;

    factoriall(1,n);
    return 0;
}

//METHOD 3.2 Parameterised way
// TC - O(N)
// SC - O(1) 
#include<bits/stdc++.h>
using namespace std;

void factoriall(int fact,int i,int n){
    if(i>n){
        cout<<fact;
        return;
    }
    factoriall(fact*i,i+1,n);
}

int main(){
    int n;
    cin>>n;

    factoriall(1,1,n);
    return 0;
}