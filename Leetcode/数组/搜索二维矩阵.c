bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row=0;//行
    int col = (*matrixColSize)-1;

    int i=0,j=0;
    while(row<matrixSize && col>=0){
        if(target > matrix[row][col]){
            row++;
        } else if(target < matrix[row][col]) {
            col--;
        } else if(target == matrix[row][col]) {
            return true;
        }
    }

    return false;

}