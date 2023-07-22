#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#define BUFFER_SIZE 10

typedef struct {
    // Define the members of the structure here
    // For example:
    int data;
} item;

item buffer[BUFFER_SIZE];
int count=0;
int in = 0;
int out = 0;

void* producer(void* arg) {
    while (true) {
        // Produce an item
        while (count == BUFFER_SIZE); // do nothing -- no free buffers
        // For this example, let's assume we're producing integers in sequence
        int produced_data = 8;
        buffer[in].data = produced_data;
        in = (in + 1) % BUFFER_SIZE;
        count++;
    }
    return NULL;
}

void* consumer(void* arg) {
    while (true) {
        // Consume an item
        while (count==0); // do nothing -- nothing to consume
        // For this example, let's assume we're returning the consumed item
        item* consumed_item = &buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        return (void*)consumed_item;
    }
    return NULL;
}

int main() {
    // Create thread handles
    pthread_t producer_thread, consumer_thread;
    
    // Start producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    // Wait for threads to finish (you can use pthread_join here)
    // Not shown in this simplified example
    
    return 0;
}
