#include "types.h"
#include "user.h"
#include "x86.h"

#define NULL 0

newpthread_sem_t forks[5];

int left(int p) {
	return p;
}

int right(int p) {
	return (p+1)%5;
}

void getForks(int p) {
	printf(1, "%d tries to get forks\n",p);
	pthread_sem_wait(&forks[left(p)]);
	pthread_sem_wait(&forks[right(p)]);
	printf(1, "%d gets forks\n",p);
}

void rev_getForks(int p) {
	printf(1, "%d tries to get forks\n",p);
	pthread_sem_wait(&forks[right(p)]);
	pthread_sem_wait(&forks[left(p)]);
	printf(1, "%d gets forks\n",p);
}

void putForks(int p) {
	printf(1, "%d puts the forks\n",p);
	pthread_sem_post(&forks[left(p)]);
	pthread_sem_post(&forks[right(p)]);
}

void philosopher(void *arg) {
	int i;
	long p=(long) arg;
	while(1) {
		for (i=0;i<100000;i++);
		getForks(p);
		for (i=0;i<100000;i++);
		putForks(p);
	}
	exit();
}

void rev_philosopher(void *arg) {
	int i;
	long p=(long) arg;
	while(1) {
		for (i=0;i<100000;i++);
		rev_getForks(p);
		for (i=0;i<100000;i++);
		putForks(p);
	}
	exit();
}


int main() {
	long i;
	for (i = 0; i < 5; i++)
	    pthread_sem_init(&forks[i], 0, 1);
	newpthread_t p[5];
	pthread_create(&p[0], NULL, rev_philosopher, (void *) 0);
	for (i = 1; i < 5; i++)
	    pthread_create(&p[i], NULL, philosopher, (void *) i);
	for (i = 0; i < 5; i++)
	    pthread_join(p[i], NULL);
	return 0; 
}