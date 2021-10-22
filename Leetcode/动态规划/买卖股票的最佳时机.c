int mathmin(int a,int b){
    return a>b?b:a;
}

int mathmax(int a,int b){
    return a>b?a:b;
}

int maxProfit(int* prices, int pricesSize){
    //双指针 找到最小的数
    if(prices == NULL || pricesSize==0)
        return 0;

    int maxPro=0;
    int min=prices[0];//记录访问过的最小值
    int i=0;
    for(i=1;i<pricesSize;i++){
        min = mathmin(min,prices[i]);
        maxPro = mathmax(maxPro,prices[i]-min);
    }

    return maxPro;

}