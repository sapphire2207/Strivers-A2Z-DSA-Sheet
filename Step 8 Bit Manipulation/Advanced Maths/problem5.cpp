// Power Exponential Method:
// Example: x = 2, n = 5 => pow(2, 5) ==> 2^5 => 32....

// Optimal Method:
// Here first we take the value 2^5... if the power is odd... then we will take one 2 out and multiply it to the answer and decrease the power..... if the power is even.... then divide the power by 2 and multiply the value with itself...
// O(log 2 base N)
#include<bits/stdc++.h>
using namespace std;

double pem(int x, int n){
        double answer = 1;
        long long m = n;
        
        if(m < 0) m = -m;
        
        while(m > 0){
            if(m % 2 == 1){
                answer = answer * x;
                m = m - 1;
            }
            else{
                m = m / 2;
                x = x * x;
            }
        }
        
        if(n < 0) answer = 1.0 / answer;
        return answer;
}

int main(){
    int x, n;
    cin >> x >> n;

    int finalAnswer = pem(x, n);
}