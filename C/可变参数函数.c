#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double average(int num,...){

    double sum = 0.0;
    va_list valist;
    int i;
    //为num个参数 初始化va_list
    va_start(valist,num);

    for(i=0;i<num;i++){
        //遍历va_list数值
        sum += va_arg(valist,int);

    }

    va_end(valist);

    return sum/num;
}

int main(){


    printf("Average of 2 3 4 5 = %f\n",average(4,2,3,4,5));
    printf("Average of 1 2 3 = %f\n",average(3,1,2,3));

    return 0;
}
