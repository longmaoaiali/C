char * longestCommonPrefix(char ** strs, int strsSize){
    //先找出最小的字符串长度
    //const int len = strsSize;
    int *strsLen = (int *)malloc(sizeof(int)*strsSize);
    int i=0;
    for(i=0;i<strsSize;i++){
        strsLen[i] = strlen(strs[i]);
    }

    int minLen=strsLen[0];
    for(i=0;i<strsSize;i++){
        if(strsLen[i]<minLen)
            minLen = strsLen[i];
    }
    

    //minLen 遍历每个字符串0-minLen-1的长度
    int j=0;
    int k=0;
    for(i=0;i<minLen;i++){
        for(j=0;j<strsSize;j++){
            //strs[0][i] == strs[j][i]
            if(strs[0][i] != strs[j][i]){
                //第i个不匹配 返回0 - i-1
				if(i=0)
					return "";
                char * res = (char*)malloc(sizeof(char)*i);
                for(k=0;k<i;k++){
                    res[k]=strs[0][k];
                }
                return res;
            }
        }
	}
    return "";
}
