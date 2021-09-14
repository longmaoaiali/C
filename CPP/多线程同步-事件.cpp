#include <iostream>
#include <windows.h>


using namespace std;

/*����event���������ں˶��󣬹ʽ���B���Ե���OpenEvent����ͨ����������ֻ�ý���A��event����ľ����
Ȼ������������ResetEvent��SetEvent��WaitForMultipleObjects�Ⱥ����С�
�˷�����ʵ��һ�����̵��߳̿�����һ�������̵߳�����*/

HANDLE hEvent;//�¼����
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






