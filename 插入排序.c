#include <stdio.h>
#include <stdlib.h>

/*插入排序的思想 参考 https://www.runoob.com/data-structures/insertion-sort.html */

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert_sort(int *a,int size){
    int i,j;
    for(i=1;i<size;i++){
        for(j=i-1;j>=0;j--){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}

int main()
{
    int a[] = {6,7,9,3,1,5,2,4,45664,2};
    int i;
    insert_sort(a,(sizeof(a)/sizeof(a[0])));

    for(i=0;i<(sizeof(a)/sizeof(a[0]));i++){
        printf("%d ",a[i]);
    }


    return 0;
}
