void rotate(int** matrix, int matrixSize, int* matrixColSize){
    //上下交换 再对角线交换

    //上下交换 i 与 (n-1)-i行交换
    int i=0,j=0,tmp=0;
    for(i=0;i<matrixSize/2;i++){
        for(j=0;j<*matrixColSize;j++){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize-1-i][j];
            matrix[matrixSize-1-i][j] = tmp;
        }
    }

    //对角线交换
    for(i=0;i<matrixSize;i++){
        for(j=0;j<*matrixColSize;j++){
            if(i>j){
                //交换
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}