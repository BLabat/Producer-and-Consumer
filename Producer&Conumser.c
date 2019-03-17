/* Producer and Consumer.
*Brandon Labat March 17, 2019*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 10
int produce();
void put();
void *producer();
void *consumer();
void consume();
int get();
int buffer[MAX];

int theProduct;

void *producer() {
	int i;
	while(1) {
		i = produce();
		put(i);
		sleep(1);
	}
}

void *consumer() {
	int i;
	while(1) {
		i = get();
		consume(i);
		sleep(1);
	}
}

int produce() {
	return theProduct + 1;
}

void consume(int i) {
	printf("Consumer consumed: %i\n",i);
	
}

void put(int i) {
	theProduct = i;
	printf("Producer put in: %d\n", i);
	return;
}

int get() {
	return theProduct;
}

void main() {
	pthread_t threads[2];
 	pthread_create(&threads[0], 0, consumer, 0);
 	pthread_create(&threads[1], 0, producer, 0);
 	pthread_join(threads[0], 0);
}