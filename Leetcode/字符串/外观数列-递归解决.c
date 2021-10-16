char * countAndSay(int n){
    //递归的做法
    //边界 n=1

    if(n===1)
        return "1";
    
    char *s = countAndSay(n-1);
    //s是n-1的数列
    //r是n-1的观察数列 
    char *r = (char*)malloc(5000);

    int count=1;//计数的变量
    int rIndex=0;//数组r的索引

    while(*s!=0){
        if(*s == *(s+1)) count++;
        else {
            r[rIndex++] = count+'0';
            r[rIndex++] = *s;
            count=1;
        }
        s++;
    }

    //最后将末尾的字符置为0
    r[rIndex]='0';
    return r;
}