//升序
int mycmp(const void* p1,const void* p2){
    const int *a = (const int*)p1;
    const int *b = (const int*)p2;

    int value=0;
    if(*a<*b)
        value=-1;
    else if(*a==*b)
        value=0;
    else value=1;

    return value;
}

int majorityElement(int* nums, int numsSize){
    //先排序  后找到最中间的索引
    int startIndex=0;
    int endIndex=numsSize-1;
    //quicksort(nums,startIndex,endIndex);
    qsort(nums,numsSize,sizeof(int),mycmp);
    return nums[numsSize/2];
}