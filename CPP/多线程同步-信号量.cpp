#include <iostream>
#include <windows.h>


using namespace std;

/*信号量的值表示剩余的资源数，=0表示信号量不可用*/

HANDLE hSemaphore;//信号量句柄
int num=1;

unsigned long __stdcall ThreadProc1(void* p){
    long count;
    while(num<100){
        WaitForSingleObject(hSemaphore,INFINITE);


        cout<<"thread 1 num = "<<num<<endl;
        ++num;
        Sleep(100);
        ReleaseSemaphore(hSemaphore,1,&count);
        //cout<<"thread 1 count = "<<count<<endl;
    }


    return 0;
}

unsigned long __stdcall ThreadProc2(void* p){
    long count;
    while(num<100){
        WaitForSingleObject(hSemaphore,INFINITE);
        cout<<"thread 2 num = "<<num<<endl;
        ++num;
        Sleep(100);
        ReleaseSemaphore(hSemaphore,1,&count);
        //cout<<"thread 2 count = "<<count<<endl;

    }


    return 0;
}


int main(){
    //第二个参数表示可用的信号量数
    hSemaphore = CreateSemaphore(NULL,1,100,"semaphore");

    CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
    CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

    Sleep(10*1000);

    system("pause");
    return 0;
}






