#include <stdio.h>
#include <pthread.h> // Include the pthread library
#include <unistd.h> // Include the usleep function
#include <time.h>

__thread int counter=0;

#define NUM_THREADS 5


void * printHello(void * index){
	counter +=10;
	usleep(1000);
	pthread_exit(NULL);
	
}

int main(){
	pthread_t threads[NUM_THREADS];
	int t,err;
	int thread_indexes[NUM_THREADS];

	for(t=0; t<NUM_THREADS; t++){
		err= pthread_create(&threads[t], NULL, printHello, NULL);
	}


	printf("the value of the counter is %d\n", counter); // Question?
	void *status;
	for(t = 0; t < NUM_THREADS; t++) {
		pthread_join(threads[t], &status);
	}

}
