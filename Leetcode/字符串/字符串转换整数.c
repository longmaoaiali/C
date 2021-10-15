int myAtoi(char * s){
    //s开始读入的时候必须是空格，符号+- 数字
    int strLen = strlen(s);
    char newStr[strLen];
    int newLen = 0;
    int i=0;
    int sig=0;//1表示负号
    //开始接受的条件
    if(s[0]==' ' || s[0]=='+' || s[0]=='-' || (s[0]>='0' && s[0]<='9')){

    //忽略前导空格
    while(s[i]==' ' && i<strLen)
        i++;


    if(s[i]=='-'){
        //保存负号
        sig=1;
        i++;
    }

    if(s[i]=='+'){
        //正号不保存
        i++;
    }

    int res=0;
    int tmp;
    while(i<strLen){
        if(s[i]>='0' && s[i]<='9'){
            //保存数字
            tmp=res*10;
            res =tmp+(s[i]-'0');
            //判断是否溢出
            if(res-(s[i]-'0') != tmp){
                if(sig){
                    return -2147483648;
                } else {
                    return pow(2,32)-1;
                }
            }

        } else{
            break;
        }  
        i++;
    }
    if(sig){
        res = -res;
    }
    return res;
    }
    
    return 0;

}