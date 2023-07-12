#include<pthread.h>
#include<stdio.h>
#include<malloc.h>

void * myThread(){
    int * ret=  (int*)malloc(sizeof(int));
    * ret=42;
    pthread_exit(ret);

}

int main(){

    pthread_t tid;
    void * status;

    pthread_create(&tid, NULL, myThread, NULL);
    pthread_join(tid, &status);

    printf("%d\n", *((int *) status));
    free(status);
    return 0;


}
