int climbStairs(int n){
    if(n<=1)
        return 1;
    if(n<3)
        return n;
    return climbStairs(n-1)+climbStairs(n-2);
}