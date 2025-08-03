//FINDING SUM OF N NATURAL NUMBERS

//METHOD 1:- Using for loop
// Intuition: 
// We can simply add numbers one by one from 1 to N.
// For eg. if N = 5, we can add 1+2+3+4+5=15.
// We can use a for loop or while loop to achieve the goal.

// TC - O(N) //SC - O(1)
#include<bits/stdc++.h>
using namespace std;
 void solve(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += i;
    }
    cout<<"The sum of the first "<<n<<" numbers is: "<<sum<<endl;
  }
 int main() {
    int n;
    cin>>n;
    solve(n);

    return 0;
  }

//METHOD 2:- Using Formula
// Intuition: We can use the formula for the sum of N numbers, i.e N(N+1)/2.

// TC - O(1) //SC - O(1)
#include<bits/stdc++.h>
using namespace std;
 void solve(int N) {
    int sum = N * (N + 1) / 2;
    cout<<"The sum of the first "<<N<<" numbers is: "<<sum<<endl;
  }
 int main() {
    int n;
    cin>>n;
    solve(n);
    return 0;
  }

//METHOD 3.1:Parameterized way 
// In this approach, instead of using a global variable for calculating the sum, we pass the sum in the parameters of the function each time we add an integer to it during the function call. The sum gets incremented by an ith integer and i get decremented by 1 in each function call. At the end when i becomes less than 1, we simply return the calculated sum until that point. 

// TC - O(N) 
// SC - O(1) 
#include<bits/stdc++.h>
using namespace std;

void sumTillN(int sum,int i){
    if(i<1){
        cout<<sum;
        return;
    }
    sumTillN(sum+i,i-1);
}

int main(){
    int n;
    cin>>n;
    
    sumTillN(0,n);

    return 0;
}

//METHOD 3.2:Parameterized way
// TC - O(N) 
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;
void sumTillN(int sum,int i,int n){
    if(i>n){
        cout<<sum;
        return;
    }
    sumTillN(sum+i,i+1,n);
}

int main(){
    int n;
    cin>>n;

    sumTillN(0,1,n);

    return 0;
}

//METHOD 4: Functional way
// Approach:
// This approach is a lot simpler than the parameterized recursion. We can visualize the sum of n natural numbers in the following way as shown below:
// sumOfNaturalNumbers(N) = N + sumOfNaturalNumbers(N-1);
// The Sum of N natural numbers would just be the Nth integer added to the Sum of (N-1) natural numbers. The base case can be visualized as if n decreases to 0, then we return 0 because the sum of 0 natural numbers is 0 only. Here, we’ve just broken the problem into 2 subparts and the answers of both these subparts would be added and stored in the Sum(n) function which would then be printed at last.

// TC - O(N)
// SC - O(N) - In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space
#include<bits/stdc++.h>
using namespace std;

int sumTillN(int n){
    if(n==0) return 0;
    return n+sumTillN(n-1);
}
int main(){
    int n;
    cin>>n;
    int ans=sumTillN(n);
    cout<<ans;
    return 0;
}
