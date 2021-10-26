/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char** res = (char**)malloc(n*sizeof(char *));
    int i;
    for(i=1;i<=n;i++){
        res[i-1] = (char*)malloc(sizeof(char)*10);
        if(i%15 ==0)
            strcpy(res[i-1],"FizzBuzz");
        else if(i%3 == 0)
            strcpy(res[i-1],"Fizz");
        else if(i%5 == 0)
            strcpy(res[i-1],"Buzz");
        else 
            sprintf(res[i-1],"%d",i);
    }
    return res;
}