int hammingDistance(int x, int y){
    int i=0;
    int count=0;
    for(i=0;i<32;i++){
        if(((x>>i)&0x1)^((y>>i)&0x1)==1){
            count++;
        }
    }

    return count;
}