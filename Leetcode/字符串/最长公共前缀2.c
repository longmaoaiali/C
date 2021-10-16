char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)
        return "";

    //char* res = (char*)malloc(sizeof(char)*strlen(*strs));
    char* res = (char*)calloc(128, sizeof(char));
    int i=0,j=0;
    for(i=0;i<strlen(*strs);i++){
        for(j=0;j<strsSize-1;j++){
            if(strs[j][i] != strs[j+1][i]){
                return res;
            }
        }
        res[i] = strs[j][i];
    }

    return res;
}