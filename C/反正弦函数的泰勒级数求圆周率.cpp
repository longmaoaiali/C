#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

double mypow(double x,int y){

    double tmp=x;

    for(int i=1;i<y;i++){
        x = x*tmp;
    }

    return x;
}

//第n项的第一个部分的值
double firstPart(int n)
{
    double firstValue=1;
    double numerator=1;
    double denumerator=1;
    for(int i=1;i<=n;i++){
        numerator *= (2*i-1);

        denumerator *= (2*i);
    }
    return numerator/denumerator;
}

double secondPart(int n)
{
    double secondValue=1;

    secondValue *= mypow(0.5,(2*n+1));
    secondValue /= (2*n+1);

    return secondValue;
}

//n>=1开始
double arcsintest(double x,int n){
    double tmp = 0;
    for(int i=1;i<=n;i++){
        tmp += firstPart(i) * secondPart(i);
    }

    return tmp;
}

int main()
{
//    int n;
//    scanf("%d",&n);

    int num = 0;
    while(cin>>num){
        double result=0;

        result = 6*(0.5+arcsintest(0.5,10));

        printf("%.*f\n",num,result);
    }




    return 0;
}
