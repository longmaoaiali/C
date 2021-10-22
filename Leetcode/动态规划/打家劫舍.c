int MathMax(int a,int b){
    return a>b?a:b;
}

int rob(int* nums, int numsSize){
    if(nums==NULL || numsSize<=0)
        return 0;

    int** dp;
    dp = (int **)malloc(sizeof(int *)*numsSize);
    int i=0;
    for(i=0;i<numsSize;i++){
        dp[i] = (int *)malloc(sizeof(int)*2);
    }
    //第一家没偷
    dp[0][0] = 0;
    //第一家偷了
    dp[0][1] = nums[0];
    
    for(i=1;i<numsSize;i++){
        dp[i][0] = MathMax(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = dp[i-1][0]+nums[i];
    }

    return MathMax(dp[numsSize-1][0],dp[numsSize-1][1]);
    
}