#include <iostream>
#include <windows.h>


using namespace std;

/*�ź�����ֵ��ʾʣ�����Դ����=0��ʾ�ź���������*/

HANDLE hSemaphore;//�ź������
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
    //�ڶ���������ʾ���õ��ź�����
    hSemaphore = CreateSemaphore(NULL,1,100,"semaphore");

    CreateThread(NULL,0,ThreadProc1,NULL,0,NULL);
    CreateThread(NULL,0,ThreadProc2,NULL,0,NULL);

    Sleep(10*1000);

    system("pause");
    return 0;
}






