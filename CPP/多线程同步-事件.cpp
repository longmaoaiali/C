#include <iostream>
#include <windows.h>


using namespace std;

/*由于event对象属于内核对象，故进程B可以调用OpenEvent函数通过对象的名字获得进程A中event对象的句柄，
然后将这个句柄用于ResetEvent、SetEvent和WaitForMultipleObjects等函数中。
此法可以实现一个进程的线程控制另一进程中线程的运行*/

HANDLE hEvent;//事件句柄
int num=1;

unsigned long __stdcall ThreadProc1(void* p){
    while(num<100){
        WaitForSingleObject(hEvent,INFINITE);


        cout<<"thread 1 num = "<<num<<endl;
        ++num;
        Sleep(100);
        SetEvent(hEvent);

    }


    return 0;
}

unsigned long __stdcall ThreadProc2(void* p){
    while(num<100){
        WaitForSingleObject(hEvent,INFINITE);
        cout<<"thread 2 num = "<<num<<endl;
        ++num;
        Sleep(100);
        SetEvent(hEvent);

    }


    return 0;
}


int main(){

    hEvent = CreateEvent(NULL,FALSE,TRUE,"event");

    CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
    CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

    Sleep(10*1000);

    system("pause");
    return 0;
}






