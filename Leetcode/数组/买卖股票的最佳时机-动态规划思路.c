int max(int a,int b){
    return a>b?a:b;

}

int maxProfit(int* prices, int pricesSize){
    //动态规划解法
    //hold 表示第i天交易完以后手里持有股票时的利润
    //noHold表示第i天交易完以后手里不持有股票时的利润
    //i=0
    int hold=-prices[0];
    int noHold=0;
    for(int i=1;i<pricesSize;i++){
        /*当天交易完之后手里持有股票也有两种情况：
		一种是当天没有任何交易，又因为当天手里持有股票，所以当天手里持有的股票其实前一天就已经持有了。
		还一种是当天买入了股票，当天能买股票，说明前一天手里肯定是没有股票的*/
        hold = max(hold,noHold-prices[i]);
		
		/*当天交易完之后手里没有股票可能有两种情况，
		一种是当天没有进行任何交易，又因为当天手里没有股票，所以当天没有股票的利润只能取前一天手里没有股票的利润。
		一种是把当天手里的股票给卖了，既然能卖，说明手里是有股票的，所以这个时候当天没有股票的利润要取前一天手里有股票的利润加上当天股票能卖的价格。
		这两种情况我们取利润最大的即可*/
        noHold = max(noHold,hold+prices[i]);

    }

    return noHold;
}