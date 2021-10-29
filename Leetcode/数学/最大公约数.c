//最大公约数
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>


/*
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int i=0;int num=0;
    for(i=1;i<=a&&i<=b;i++){
        if(b%i==0 && a%i==0){
            num=i;
        }
    }

    printf("%d %d is %d",a,b,num);
}
*/

int hcf(int a,int b){
    if(b!=0){
        hcf(b,a%b);
    } else {
        return a;
    }
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    printf("%d %d is %d",a,b,hcf(a,b));
}
