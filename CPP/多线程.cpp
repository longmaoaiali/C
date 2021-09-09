#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5
pthread_mutex_t mutex;

void *printHello(void *threadid){



    int tid = *((int*)threadid);
    cout<<"tid  = "<<tid<<endl;
    cout<<"Hello world!! thread id is "<<tid<<endl;

    pthread_exit(NULL);

}

int main()
{
    pthread_t threads[NUM_THREADS];//存放线程标识符的数组
    int index[NUM_THREADS];//自定义的线程编号 传入线程处理函数的参数

    int i;
    int ret;

    for(i=0;i<NUM_THREADS;i++){
        cout << "main() : 创建线程, " << i << endl;
        index[i] = i;

        ret = pthread_create(&threads[i],NULL,printHello,(void*)(&index[i]));

        if(ret){
            cout<<"create thread failed, ret = "<<ret<<endl;
            exit(-1);
        }
    }

    return 0;

}




