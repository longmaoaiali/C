//pow n次方实现
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>



int main(){
    int a,n;

    while(scanf("%d",&a)!=EOF){
        scanf("%d",&n);
    int b=n;
    int result=1;

    while(n){
        result = result*a;
        n--;
    }


    printf("%d %d %d\n",a,b,result);
    }

}
