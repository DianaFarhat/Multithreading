#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

void * printHello(void *index) {
    printf("\n%d: Hello CMPS 272!\n", *((int *) index));
    pthread_exit(NULL);
}

int main(){

    pthread_t threads [NUM_THREADS];
    int t, err;
    int ids[NUM_THREADS];
    for (t=0; t< NUM_THREADS; t++){
        ids[t]=t;
        printf("Creating thread: %d\n", t);
        err= pthread_create(&threads[t], NULL, printHello, &ids[t]);
        if (err !=0){
            printf("Something went wrong!");
            exit(-1);
        } 
    }
    pthread_exit(NULL);
}
