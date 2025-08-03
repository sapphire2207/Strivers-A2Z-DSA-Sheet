// Find the minimum number of Bit flips to convert into the number

// Example:
// 1) Start = 10 ..... Goal = 7
//         1010          0111
// Therefore we need 3 bit flips....

// When we do xor of the two numbers we know how many times should we flip in the form of number of ones.... to know the count of the number of ones... use a for loop and check if the ith bit is set or not.....
// TC: O(31)
int MinBitFlips(int start, int goal){
    int count=0;
    int ans = start ^ goal;
    for(int i = 0; i < 31; i++){
        if(ans & (1 << i)){
            count++;
        }
    }
    return count;
}