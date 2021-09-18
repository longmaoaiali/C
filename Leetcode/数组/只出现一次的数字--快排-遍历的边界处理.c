int partition(int *nums,int startIndex,int endIndex){

    int value = nums[startIndex];
    while(startIndex <endIndex){
        
        while(startIndex <endIndex && nums[endIndex]>=value)
            endIndex--;
        
        nums[startIndex] = nums[endIndex];

        while(startIndex <endIndex && nums[startIndex]<=value)
            startIndex++;
        
        nums[endIndex] = nums[startIndex];
    }

    nums[startIndex] = value;
    return startIndex;

}

void quickSort(int *nums,int startIndex,int endIndex){
    if(startIndex<endIndex){
        int position = partition(nums,startIndex,endIndex);
        quickSort(nums,startIndex,position-1);
        quickSort(nums,position+1,endIndex);
    }

}

int singleNumber(int* nums, int numsSize){
    if(numsSize==0 || nums==NULL)
        return 0;

    if(numsSize == 1)
        return nums[0];

    //快排这个数组
    quickSort(nums,0,numsSize-1);
    int i;
    for(i=0;i<numsSize;i++){
        if(i==0 && nums[i]!= nums[i+1]){
            return nums[i];
        }

        if(i==numsSize-1 && nums[i-1]!=nums[i]){
            return nums[i];
        }
        if(i<numsSize-1 && i>0) {
            if((nums[i] != nums[i-1]) && (nums[i] != nums[i+1])){
                return nums[i];
            }
        }
        
    }

    return 0;
}