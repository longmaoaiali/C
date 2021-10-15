int strStr(char * haystack, char * needle){
    if(haystack==NULL || needle==NULL)
        return 0;
    

    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    if(needleLen==0)
        return 0;
    if(haystackLen==0)
        return -1;
    

    int i=0;
    for(i=0;i<=haystackLen-needleLen;i++){
        int tmpIndex=i;
        int j=0;
        while(j<needleLen){
            if(haystack[i+j] != needle[j]){
                break;
            }
            
            j++;

            if(j==needleLen){
                return tmpIndex;
            }
        }
    }

    return -1;

}