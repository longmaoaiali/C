//int 型整数回文
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>



int main(){

    int num;
    scanf("%d",&num);
    int originNum=num;
    int reverseNum=0;
    while(num){
        int tmp = num%10;
        reverseNum = reverseNum*10+tmp;
        num=num/10;
    }

    if(originNum == reverseNum){
        printf("is ok, originNum is %d reverseNum is %d\n",originNum,reverseNum);
    } else {
        printf("is not ok, originNum is %d reverseNum is %d\n",originNum,reverseNum);
    }

    return 0;
}
