int* plusOne(int* digits, int digitsSize, int* returnSize){
    //判断最后一位是不是9
    if(digits[digitsSize-1] != 9){
        digits[digitsSize-1] += 1;
        *returnSize = digitsSize;
        return digits;
    }

    //遍历数组 找到 digits[i] != 9 或者 i=0
    int i=digitsSize-1;
    int j;
    while(i>=0 && digits[i]==9){
        i--;
    }

    if(i<0){
        //999 --> 1000的情况
        int size = digitsSize+1;
        *returnSize = size;
        digits = malloc(sizeof(int)*size);
        digits[0]=1;
        for(j=1;j<size;j++){
            digits[j] = 0; 
        }
    }


    if(i>=0 && digits[i] != 9)
    {
		//得考虑989 499
        //499 --> 500
        digits[i] += 1;
        for(j=i+1;j<digitsSize;j++){
            digits[j] = 0;
        }

    }

        
    return digits;
    

}