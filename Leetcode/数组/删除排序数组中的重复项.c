int removeDuplicates(int* nums, int numsSize){

    if(nums==NULL && numsSize>1)
        return -1;

    int i=0,j=1;

    for(j=1;j<numsSize;j++){
        if(nums[j]>nums[i]){
            i++;
            nums[i] = nums[j];
        }
        //不大于就是等于 j++继续，i不加
    }

    return i+1;
    
}