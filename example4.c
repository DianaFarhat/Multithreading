#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> // for exit(-1)

#define NUM_THREADS 5

struct coord{
   int x;
   int y; 
};
void *printHello(void * point) {
    printf("\n%d, %d: Hello CMPS 272!\n", ((struct coord *) point)-> x, ((struct coord *) point)-> y);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int t, err;
    struct coord point={3, 5};
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %d\n", t);
        err = pthread_create(&threads[t], NULL, printHello, &point); 
        if(err != 0) exit(-1);
    }

    pthread_exit(NULL); // Question? replace with exit(0);
}
