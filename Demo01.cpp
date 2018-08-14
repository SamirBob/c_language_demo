#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;//创建互斥锁

//打印机
void printer(char *str)
{
    pthread_mutex_lock(&mutex);//上锁
    while(*str != '\0')
    {
        putchar(*str);
        fflush(stdout);
        str++;
        sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);//解锁
}

//线程一
void *thread_fun_1(void *arg)
{
    char *str = "hello";
    printer(str);//打印
}

//线程二
void *thread_fun_2(void *arg)
{
    char *str = "world";
    printer(str);//打印
}

int main(int argc, char const *argv[])
{
    pthread_t tid1,tid2;

    pthread_mutex_init(&mutex,NULL);//初始化互斥锁

    //创建2个线程
    pthread_create(&tid1,NULL,thread_fun_1,NULL);
    pthread_create(&tid2,NULL,thread_fun_2,NULL);

    //等待线程结束，回收其资源
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    return 0;
}

