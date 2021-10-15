int firstUniqChar(char * s){
    //构建一个int型数组  记录字符出现的次数
    //26个字符
    int count[26]={0};
    int len = strlen(s);
    int i=0;
    for(i=0;i<len;i++){
        count[s[i]-'a']++;
    }

    //找出出现一个的索引
    for(i=0;i<len;i++){
        if(count[s[i]-'a'] == 1){
            return i;
        }
    }

    return -1;
}