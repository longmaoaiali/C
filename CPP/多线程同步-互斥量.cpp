#include <iostream>
#include <windows.h>


using namespace std;

int number = 1;
HANDLE hMutex;//���廥����

unsigned long __stdcall ThreadProc1(void *p){
    while(number<100){
        WaitForSingleObject(hMutex,INFINITE);

        cout<<"thread 1 :"<<number<<endl;
        ++number;
        Sleep(100);
        ReleaseMutex(hMutex);

    }


    return 0;
}

unsigned long __stdcall ThreadProc2(void *p){
    while(number<100){
        WaitForSingleObject(hMutex,INFINITE);

        cout<<"thread 2 :"<<number<<endl;
        ++number;
        Sleep(100);
        ReleaseMutex(hMutex);

    }


    return 0;
}


int main(){

    hMutex = CreateMutex(NULL,false,"mutex"); //����������

    CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
    CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);



    Sleep(10*1000);
    system("pause");
    return 0;
}




