#include <iostream>
#include <windows.h>


using namespace std;

CRITICAL_SECTION critical;
int num=1;

unsigned long __stdcall ThreadProc1(void* p){
    while(num<100){
        EnterCriticalSection(&critical);
        cout<<"thread 1 num = "<<num<<endl;
        ++num;
        Sleep(100);
        LeaveCriticalSection(&critical);

    }


    return 0;
}

unsigned long __stdcall ThreadProc2(void* p){
    while(num<100){
        EnterCriticalSection(&critical);
        cout<<"thread 2 num = "<<num<<endl;
        ++num;
        Sleep(100);
        LeaveCriticalSection(&critical);

    }


    return 0;
}


int main(){
    InitializeCriticalSection(&critical);
    CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
    CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

    Sleep(10*1000);

    system("pause");
    return 0;
}






