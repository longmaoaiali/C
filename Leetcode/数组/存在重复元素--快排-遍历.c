int partition(int *nums,int startIndex,int endIndex){
    //取数组开始的数为标准
    int value = nums[startIndex];

    while(startIndex<endIndex){
        while(startIndex<endIndex && nums[endIndex]>=value)
            endIndex--;
        nums[startIndex] = nums[endIndex];

        while(startIndex<endIndex && nums[startIndex]<=value)
            startIndex++;
        nums[endIndex] = nums[startIndex];

    }

    nums[startIndex] = value;
    return startIndex;


}


void quickSort(int *nums,int startIndex,int endIndex){
    if(startIndex<endIndex)
    {
        int position = partition(nums,startIndex,endIndex);
        quickSort(nums,startIndex,position-1);
        quickSort(nums,position+1,endIndex);

    }
}

bool containsDuplicate(int* nums, int numsSize){
    //暴力循环超时
    //快排加遍历一次

    if(nums==NULL || numsSize==0)
        return false;
    
    quickSort(nums, 0, numsSize-1);

    int i=0;
    while(i<numsSize-1){
        if(nums[i]==nums[++i]){
            return true;
        }
    }

    return false;

}