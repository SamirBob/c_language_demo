/**
  * MutexDemo.c
  * 使用互锁来实现线程同步
  */
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex; //定义锁

void *print_msg(void *arg){
    int i=0;
    pthread_mutex_lock(&mutex) //上锁
    for(i=0;i<15;i++){
        printf("output : %d\n",i);
        usleep(100);
    }
    pthread_mutex_unlock(&mutex) //解锁
}

int main(int argc,char** argv){
    pthread_t id1;
    pthread_t id2;
    pthread_mutex_init(&mutex,NULL);//初始化锁
    pthread_create(&id1,NULL,print_msg,NULL);
    pthread_create(&id2,NULL,print_msg,NULL);
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    pthread_mutex_destroy(&mutex);//销毁锁
    return 1;
}
