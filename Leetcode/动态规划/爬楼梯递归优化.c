int climbStairs(int n){
    return climbStairsHelper(n,1,1);
}

//累加的结果都保存在b中
int climbStairsHelper(int n,int a,int b){
    if(n<=1)
        return b;

    return climbStairsHelper(n-1,b,a+b);
}