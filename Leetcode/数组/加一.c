int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i;
    for(i=digitsSize-1;i>=0;i--){
        if(digits[i] == 9){
            digits[i]=0;
            if(i==0){
                *returnSize = digitsSize+1;
            }
        } else {
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }
    }

    //数组拉长1
    int *array = (int *)malloc(sizeof(int)*(*returnSize));
    array[0]=1;
    for(i=1;i<*returnSize;i++){
        array[i]=0;
    }

    return array;
}