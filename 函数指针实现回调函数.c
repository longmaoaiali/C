#include <stdio.h>
#include <stdlib.h>

void initRandomArray(int *array,int arraySize, int(*fun)(void)){
    int i;
    for(i=0;i<arraySize;i++){
        array[i] = fun();
    }

}

int getNextRandomValue(void)
{
    return rand();
}


int main()
{
    int array[10];

    initRandomArray(array,10,getNextRandomValue);
    int i;
    for(i=0;i<10;i++){
        printf("%d ",array[i]);
    }

    printf("\n");
    return 0;
}
