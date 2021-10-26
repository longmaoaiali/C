int singleNumber(int* nums, int numsSize){
    int i=0;
    int result=0;
    for(i=0;i<numsSize;i++){
        result ^= nums[i];
        printf("nums[i] = %d\n",nums[i]);
    }
    return result;
}

//a^a=0；自己和自己异或等于0
//a^0=a；任何数字和0异或还等于他自己
//a^b^c=a^c^b；异或运算具有交换律