#include <stdio.h>
#include <pthread.h> // Include the pthread library
#include <unistd.h> // Include the usleep function
#include <time.h>



#define NUM_THREADS 5

int counter[NUM_THREADS]={0};

void * printHello(void * index){
	int ind= *(int *)(index);
	counter[ind] +=10;
	usleep(1000);
	pthread_exit(NULL);
	
}

int main(){
	pthread_t threads[NUM_THREADS];
	int t,err;
	int thread_indexes[NUM_THREADS];

	for(t=0; t<NUM_THREADS; t++){
		thread_indexes[t] = t;
		err= pthread_create(&threads[t], NULL, printHello, &thread_indexes[t]);
	}

	void *status;
	for(t = 0; t < NUM_THREADS; t++) {
		pthread_join(threads[t], &status);
		
	}
	
	int total_counter=0;
	for(t=0; t<NUM_THREADS;t++){
	
		total_counter+= counter[t];
	}
	
	printf("the value of the counter is %d\n", total_counter); // Question?

}
