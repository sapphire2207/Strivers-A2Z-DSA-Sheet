// Toggle the ith Bit

int toggleIthBit(int n, int k){
    // Left shift 1 by k places and perform xor with number
    int answer;
    answer = (n ^ (1 << k));
}