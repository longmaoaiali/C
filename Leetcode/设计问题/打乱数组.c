typedef struct {
    int oldNums[200];
    int randNums[200];
    int size;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    int i=0;
    for(i=0;i<numsSize;i++){
        obj->oldNums[i] = nums[i];
        obj->randNums[i] = nums[i];
    }
    obj->size = numsSize;
    return obj;
}

int* solutionReset(Solution* obj, int* retSize) {
    int* result = (int *)malloc(sizeof(int)*obj->size);
    int i=0;
    for(i=0;i<obj->size;i++){
        result[i] = obj->oldNums[i];
    }
    *retSize = obj->size;
    return result;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    //随机交换两个数
    int m = rand() % obj->size;
    int n = rand() % obj->size;
    int tmp = obj->randNums[m];
    obj->randNums[m] = obj->randNums[n];
    obj->randNums[n] = tmp;

    int* result = (int *)malloc(sizeof(int)*obj->size);
    int i=0;
    for(i=0;i<obj->size;i++){
        result[i] = obj->randNums[i];
    }
    *retSize = obj->size;
    return result;
}

void solutionFree(Solution* obj) {
    if(obj)
        free(obj);
    
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/