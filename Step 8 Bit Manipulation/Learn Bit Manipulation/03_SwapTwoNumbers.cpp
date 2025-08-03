// Swap two numbers a and b

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    // Swap using extra variable
    int temp;
    temp = a;
    a = b;
    b = temp;

    // Swap using xor
    // Xor ==> if there are even number of one's, it's xor is 0
    // Xor ==> if there are odd number of one's, it's xor is 1
    // Now if we do xor of two same numbers, it's answer is 0
    // i.e 5 ^ 5 => 1 0 1
    //              1 0 1
    //            ^ 0 0 0
    // So use XOR for saving the space
    a = a ^ b;
    b = a ^ b; // Here now b is: (a ^ b) ^ b => when this is simplified it becomes a ^ (b ^ b), since xor of two numbers is zero => it's answer is a, so we are storing the value of 'a' in 'b'
    a = a ^ b; // Here now a is: (a ^ b) ^ b => because now b stores the value a, so eventually it becomes (a ^ b) ^ a, since xor of two numbers is zero => it's answer is b, so we are storing the value of 'b' in 'a'
    cout << a << " " << b;
}
