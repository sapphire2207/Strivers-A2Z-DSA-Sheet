// Count number of set bits

int countSetBits(int n){
    int count = 0;
    while(n > 1){
        if(n & 1) count++; // count += n & 1; // if(n % 2 == 1) count++;
        n = n / 2; // n = n >> 1;
    }
    if(n == 1) count++;
    return count;
}

// Other approach is to keep on performing n & n-1 till you get zero, i.e at every step we are setting the right most bit to zero
// TC: O(Number of set bits)
int countSetBits(int n){
    int count = 0;
    while(n != 0){
        n = n & n-1;
        count++;
    }
    return count;
}