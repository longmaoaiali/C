bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    //暴力求解 遍历

    int i,j,k;

    //查看每行是否有重复
    for(k=0;k<boardSize;k++){
        //第K行 使用i j 两个索引看数字是否重复
        for(i=0;i<(*boardColSize)-1;i++){
            for(j=i+1;j<*boardColSize;j++){
                if(board[k][i] == '.'){
                    //i 不是数字就直接跳出当前循环 继续i++
                    break;
                }

                if(board[k][j]=='.'){
                    //j 不是数字就直接继续j++
                    continue;
                }

                //i j 都是数字就比较 如果相同直接返回false 否则继续遍历
                if(board[k][i] == board[k][j]){
                    return false;
                }
            }
        }
        
    }


    //查看每列是否重复
    for(k=0;k<*boardColSize;k++){
        //第K列 使用i j 两个索引看数字是否重复
        for(i=0;i<boardSize-1;i++){
            for(j=i+1;j<boardSize;j++){
                if(board[i][k] == '.'){
                    //i 不是数字就直接跳出当前循环 继续i++
                    break;
                }

                if(board[j][k]=='.'){
                    //j 不是数字就直接继续j++
                    continue;
                }

                //i j 都是数字就比较 如果相同直接返回false 否则继续遍历
                if(board[i][k] == board[j][k]){
                    return false;
                }
            }
        }
        
    }

    //行列都没有重复 查询单元格是够重复
    int a=0,b=0,c=0,d=0;
	int row=0,col=0;
	int num=0;
	
	for(num=0,num<9;num++){
		for(a=row;a<3+row;a++){
			for(b=col;b<col+3;b++){
				if(board[a][b] == '.')
				{
					continue;
				}
				
				for(c=row;c<row+3;c++){
					for(d=col;d<col+3;d++){
						if(board[c][d] == '.')
							continue;
						else if((board[a][b] == board[c][d]) && ((a!=c)||(c!=d))){
							return false;
						}
					}
				}
			}
		}
		
		//row col移动到下一个3*3矩阵
		col += 3;
		if(col>=9){
			col=0;
			row += 3;
		}
	}

    return true;
}