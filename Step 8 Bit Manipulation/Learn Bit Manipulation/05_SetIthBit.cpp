// Set the ith Bit of a number

int setIthBit(int n, int k) {
    // Left shift '1' by 2 places and perform | with number
    int answer2;
    answer2 = n | (1 << k);
    return answer2;
}