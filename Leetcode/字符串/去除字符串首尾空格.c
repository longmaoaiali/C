#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void trim(char* strIn,char* strOut){
	//双指针
	int i=0;
	int j=strlen(strIn)-1;
	
	while(strIn[i]==' ')
		i++;
	
	while(strIn[j]==' ')
		j--;
	
	strncpy(strOut,strIn+i,j-i+1);
	strOut[j-i+1] = '\0';
}