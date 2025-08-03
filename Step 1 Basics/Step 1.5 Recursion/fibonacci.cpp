//FINDING THE FIBONACCI SEQUENCE FOR A GIVEN NUMBER

//METHOD 1:- Using For Loop and an extra array
// Intuition: As we know fib(i) = fib(i-1) + fib(i-2).Simply iterate and go on calculating the ith term in the series.

//TC - O(n) + O(n)
//SC - O(n)
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  if (n == 0) {
    cout << 0;
  } else if (n == 1) {
    cout << 0 << " " << 1 << "\n";
  } else {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
    for (int i = 0; i <= n; i++) {
      cout << fib[i] << " ";
    }
  }
}

//METHOD 2:-Space Optimised Method
// Intuition: For calculating the ith term we only need the last and second last term i.e (i-1)th and (i-2)th term, so we don't need to maintain the whole array.

// TC: O(N)
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
	if (n == 0) {
	    cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
		cout << 0;
	}
	else {
		int secondLast = 0;//for (i-2)th term
		int last = 1;//for (i-1)th term
		cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
		cout << secondLast << " " << last << " ";
		int current; //for ith term
		for (int i = 2; i <= n; i++) {
			current = last + secondLast;
			secondLast = last;
			last = current;
			cout << current << " ";
		}
	}
}

//METHOD 3.1:Using Recursion printing the fibonacci number
// In this approach, instead of printing the Fibonacci series till N, we’re going to print the Nth Fibonacci number using functional recursion with multiple function calls.
// One may wonder how multiple-function calls work. Let’s understand through an illustration below:
// Similar kinds of multiple-function calls would be used in implementing the Fibonacci series where any Nth Fibonacci number can be written as a sum of (N-1)th and (N-2)th Fibonacci numbers. So, the function result would look like this:
// Fibonacci(N) = Fibonacci(N-1) + Fibonacci(N-2)
// Results from both the function calls would be summed and returned to the main function call.

//TC - O(2^N) {This problem involves two function calls for each iteration which further expands to 4 function calls and so on which makes worst-case time complexity to be exponential in nature}.
//SC - O(N) - At maximum there could be N function calls waiting in the recursion stack since we need to calculate the Nth Fibonacci number for which we also need to calculate (N-1) Fibonacci numbers before it 
#include<bits/stdc++.h>
using namespace std;

int fibonaccii(int n){
    if(n<=1) return n;

    int last=fibonaccii(n-1);
    int secondlast=fibonaccii(n-2);
    return last+secondlast;
}

int main(){
    int n;
    cin>>n;

    cout<<fibonaccii(n);
    return 0;
}

//METHOD 3.2:- Using Recusrion printing the entire fibonacci sequence
//TC - O(N)*N
//SC - O(N)
// #include<iostream>
// using namespace std;

// int fibonacci(int n) {
//     if(n <= 1) {
//         return n;
//     }
//     return fibonaccii(n-1) + fibonaccii(n-2);
// }

// void printFibonacci(int n) {
//     for(int i = 0; i < n; i++) {
//         cout << fibonaccii(i) << " ";
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of terms: ";
//     cin >> n;
    
//     if(n <= 0) {
//         cout << "Please enter a positive integer." << endl;
//         return 0;
//     }

//     cout << "Fibonacci sequence: ";
//     printFibonacci(n);

//     return 0;
// }


//METHOD 3.3:- Using Recursion and using only one function call
//TC - O(N)
//SC - O(1)
// #include<iostream>
// using namespace std;

// int fibonacci(int n, int current = 0, int next = 1) {
//     if(n == 0) {
//         return current;
//     }
//     cout << current << " ";
//     return fibonaccii(n - 1, next, current + next);
// }

// int main() {
//     int n;
//     cout << "Enter the number of terms: ";
//     cin >> n;
    
//     if(n <= 0) {
//         cout << "Please enter a positive integer." << endl;
//         return 0;
//     }

//     cout << "Fibonacci sequence: ";
//     fibonaccii(n);

//     return 0;
// }
