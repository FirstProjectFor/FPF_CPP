#include <iostream>

#include <thread>

using namespace std;

#define NUM_THREADS 5

void *sayHello(void *threadId)
{
    int id = *((int *)threadId);
    cout << "Hello, thread run:" << id << endl;
}

int main(int argc, char const *argv[])
{

    pthread_t threadIdList[NUM_THREADS];
    int indexList[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        cout << "create thread: " << i << endl;
        indexList[i] = i;
        int ret = pthread_create(&threadIdList[i], NULL, sayHello, (void *)(&(indexList[i])));
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }

    //结束创建的线程
    pthread_exit(NULL);

    return 0;
}
