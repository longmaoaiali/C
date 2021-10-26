int countPrimes(int n){
    //创建一个1,0 数组 1表示是质数 0表示不是质数
    int* array = (int *)calloc(n,sizeof(int));
    int i;
    for(i=0;i<n;i++){
        //默认全是质数
        array[i]=1;
    }

    for(i=2;i*i < n;i++){
        if(array[i]){
            int x=i;
            while(i*x<n){
                array[i*x] = 0;
                x++;
            }
        }
    }

    int result=0;
    for(i=2;i<n;i++){
        if(array[i]){
            result++;
        }
    }

    return result;
}