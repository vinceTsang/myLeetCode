//统计数n的二进制表示中1的个数，只需每次减去最后一个1即可
int hammingWeight(uint32_t n) {
    int counts=0;
    while(n!=0){
        n -= n&-n; //low_bit(n);
        counts++;
    }
    return counts;
}
