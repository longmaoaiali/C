int MathMax(int a,int b){
    return a>b?a:b;
}

int maxSubArray(int* nums, int numsSize){
    //dp[i]=num[i]+max(dp[i-1],0);
   
    int* dp = (int *)malloc(sizeof(int)*numsSize);

    dp[0] = nums[0];
    int max=dp[0];
    int i=0;
    for(i=1;i<numsSize;i++){
        dp[i]=nums[i]+MathMax(dp[i-1],0);
        max = MathMax(max,dp[i]);
    }

    return max;
}