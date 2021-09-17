//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
/*
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
*/

void rotate(int* nums, int numsSize, int k){

    if(nums==NULL || numsSize==0)
        return;

    int* tmp = malloc(numsSize*sizeof(int)); 
    int i;
    //临时数组存储原数据
    for(i=0;i<numsSize;i++){
        tmp[i] = nums[i];
    }

    for(i=0;i<numsSize;i++){
        nums[(i+k)%numsSize] = tmp[i];
    }  
    return;
}