uint32_t reverseBits(uint32_t n) {
    int res=0;
    int i=0;
    for(i=0;i<32;i++){
        res |= (n & 1) << (31 - i);
        n >>= 1;
    }

    return res;
}