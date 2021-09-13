#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return a>=b?a:b;
}

int main()
{
    int (*fun)(int ,int) = &max;
    int a,b,c;
    printf("输入三个数字，以,分隔\n");
    scanf("%d,%d,%d",&a,&b,&c);

    int d = fun(fun(a,b),c);

    printf("最大的数是 %d\n",d);


    return 0;
}
