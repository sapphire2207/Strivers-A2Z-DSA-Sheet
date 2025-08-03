// Remove the last set bit from the right

// Example 1: n = 16;
// Now take n & n-1 for the answer
// Its because:
// n   => 10000
// n-1 => 01111
// Here if we perform &, we get the number 00000

// Example 2: n = 40;
// Now take n & n-1 for the answer
// Its because: 
// n   => 101000
// n-1 => 100111
// Here if we perform &, we get the number 100000

int removeRightMostSetBit(int n){
    int answer;
    answer = n & n-1;
    return answer;
}