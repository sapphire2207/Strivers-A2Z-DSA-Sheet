// Clear the ith bit

int clearIthBit(int n, int k) {
    // Left shift '1' by 2 places and take negation of it and then perform & with number
    int answer2;
    answer2 = n & ~(1 << k);
    return answer2;
}