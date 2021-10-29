//一元二次方程
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);

    float d = sqrt(b*b-4*a*c);

    float x1 = (-b+d)/(2*a);
    float x2 = (-b-d)/(2*a);
    printf("%f, %f",x1,x2);
    return 0;
}
