#include <stdio.h>

#define true 1

void swap(int* a,int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}



void quick_sort(int *array,int startIndex,int endIndex)
{
    if(endIndex<=startIndex)
        return -1;

    int value  = array[endIndex];
    int i=startIndex;
    int j=endIndex-1;

    while(true){
        //找到大于value的i值
        while(array[i]<value && i<endIndex){
            i++;
        }

        while(array[j]>value && j>startIndex){
            j--;
        }

        if(i<j){
            swap(&array[i],&array[j]);
            i++;
            j--;
        }else{
            break;
        }
    }

    swap(&array[i],&array[endIndex]);
    quick_sort(array,startIndex,i-1);
    quick_sort(array,i+1,endIndex);

}


int main() {

    int a[10] = {23,11,4,54,6,7,85,2,32,4354};
    int i;
    quick_sort(a,0,(sizeof(a)/sizeof(a[0]))-1);

    for(i=0;i<(sizeof(a)/sizeof(a[0]));i++){
        printf("%d ",a[i]);
    }

    return 0;
}
