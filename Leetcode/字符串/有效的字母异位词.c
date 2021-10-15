bool isAnagram(char * s, char * t){
    //字母异同词 长度相同 
    int sLen = strlen(s);
    int tLen = strlen(t);

    if(sLen==1 && tLen==1 && s[0]==t[0])
        return true;

    if(sLen != tLen || strcmp(s,t)==0)
        return false;

    int i=0;

    int sCount[26]={0};
    int tCount[26]={0};
    for(i=0;i<sLen;i++){
        sCount[s[i]-'a']++;
        tCount[t[i]-'a']++;
    }

    for(i=0;i<26;i++){
        if(sCount[i] != tCount[i]){
            return false;
        }
    }

    return true;
}