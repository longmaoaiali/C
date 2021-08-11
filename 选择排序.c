#include <stdio.h>

void swap(int* a,int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void select_sort(int *a,int size){
    int i,j;
    int min;
    for(i=0;i<size;i++){
        min=i;//默认第i个最小
        for(j=i+1;j<size;j++){
            if(a[min]>a[j]){
                min=j;
            }

        }
        //交换a[i] a[min]
        if(min != i){
            swap(&a[min],&a[i]);
        }
    }
}

int main() {

    int a[10] = {23,11,4,54,6,7,85,2,32,4354};
    int i;
    select_sort(a,sizeof(a)/sizeof(a[0]));

    for(i=0;i<(sizeof(a)/sizeof(a[0]));i++){
        printf("%d ",a[i]);
    }

    return 0;
}
