int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result;

    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(target == nums[j]+nums[i]){
                result = malloc(2*sizeof(int));
                result[0]=i;
                result[1]=j;
                *returnSize = 2;
                return result;
            }
        }

    }

    return NULL;
}