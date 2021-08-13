#include <stdio.h>

void swap(int* a,int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}


void shell_sort(int *a,int size){
    int gap;//增量 一般就是分为多少组
    int i,j;

    for(gap=size/2;gap>0;gap = gap/2){
        for(i=gap;i>0;i--){
            for(j=i-1;j<size;j=j+gap){
                //找到这一组数中最小的放在a[j]上面
                //tmp = a[j];
                int minIndex = j;
                int index=j;
                while(index<size){
                    if(a[index] < a[minIndex])
                        minIndex=index;
                    index += gap;

                }
                //a[j]=a[minIndex];
                //a[minIndex] = tmp;
                swap(&a[j],&a[minIndex]);
            }
        }
    }
}


int main() {

    int a[10] = {23,11,4,54,6,7,85,2,32,4354};
    int i;
    shell_sort(a,sizeof(a)/sizeof(a[0]));

    for(i=0;i<(sizeof(a)/sizeof(a[0]));i++){
        printf("%d ",a[i]);
    }

    return 0;
}
