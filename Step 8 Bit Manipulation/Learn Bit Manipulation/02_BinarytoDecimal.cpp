// Converting a binary number to decimal number

#include<bits/stdc++.h>
using namespace std;

// TC: O(length of string)
// SC: O(1)
int convert2Decimal(string bnumber){
    int length = bnumber.size();
    int powerof2 = 1;
    int decimal_number = 0;
    for(int i = length - 1; i <= 0; i ++){
        if(bnumber[i] == '1'){
            decimal_number = decimal_number + powerof2;
        }
        powerof2 = powerof2 * 2;
    }
    return decimal_number;
}

int main(){

}