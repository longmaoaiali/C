bool isPalindrome(char * s){
    //只保留字符串的数字和字母字符
    int strLen = strlen(s);
    char newStr[strLen];
    int newLen=0;

    int i=0;
    for(i=0;i<strLen;i++){
        if((s[i]>='a'&&s[i]<='z') || (s[i]>=0&&s[i]<=9) || (s[i]>='A'&&s[i]<='Z')){
            newStr[newLen] = s[i];
            newLen++;
        }
    }

    //将字符串里面的大写字母转换为小写字母
    for(i=0;i<newLen;i++){
        if(newStr[i]>='A'&& newStr[i]<='Z'){
            newStr[i] += 32;
        }
    }

    for(i=0;i<newLen/2;i++){
        if(newStr[i] != newStr[newLen-1-i])
            return false;
    }

    return true;
}