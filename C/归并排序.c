#include <stdio.h>

void swap(int* a,int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}


void merge_array(int *array,int startIndex,int midIndex,int endIndex,int *tempArray){
    int leftIndex = startIndex;//左边数组的第一个索引
    int rightIndex = midIndex+1;//右边数组的第一个索引
    int i = 0;

    while(leftIndex <=midIndex && rightIndex<=endIndex){
        if(array[leftIndex] < array[rightIndex]){
            tempArray[i] = array[leftIndex];
            i++;
            leftIndex++;
        } else {
            tempArray[i] = array[rightIndex];
            i++;
            rightIndex++;
        }
    }

    //走到这里表示有一个数组已经遍历完了
    while(leftIndex<=midIndex){
        tempArray[i] = array[leftIndex];
        i++;
        leftIndex++;
    }

    while(rightIndex<=endIndex){
        tempArray[i] = array[rightIndex];
        i++;
        rightIndex++;
    }

    i=0;
    while(startIndex<=endIndex){
        array[startIndex]=tempArray[i];
        i++;
        startIndex++;
    }

}


void merge_devide(int *array,int startIndex,int endIndex,int *tempArray){
    if(startIndex<endIndex){
        int mid = (startIndex+endIndex)/2;
        //拆分
        merge_devide(array,startIndex,mid,tempArray);
        merge_devide(array,mid+1,endIndex,tempArray);

        //合并
        merge_array(array,startIndex,mid,endIndex,tempArray);
    }
}

void merge_sort(int *a,int size){
    int *temp = malloc(size*sizeof(int));

    if(!temp){
        perror("malloc failded");
        return;
    }

    merge_devide(a,0,size-1,temp);

    //a=temp;
    if(temp)
        free(temp);
}


int main() {

    int a[10] = {23,11,4,54,6,7,85,2,32,4354};
    int i;
    merge_sort(a,sizeof(a)/sizeof(a[0]));

    for(i=0;i<(sizeof(a)/sizeof(a[0]));i++){
        printf("%d ",a[i]);
    }

    return 0;
}
