#include "types.h"
#include "user.h"
#include "x86.h"

#define NULL 0

static volatile int done = 0;
newpthread_mutex_t mutex;
newpthread_cond_t cond;

void child(void *arg)
{
  
  pthread_mutex_lock(&mutex);
  printf(1, "child starts\n");
  sleep(2);
  done = 1;
  pthread_cond_signal(&cond);
  printf(1, "child finished\n");
  pthread_mutex_unlock(&mutex);
  exit();
}

int main(){
  printf(1, "parent begins\n");
  pthread_mutex_init(&mutex);
  pthread_cond_init(&cond);
  newpthread_t p;
  pthread_create(&p, NULL, child,(void*)NULL);
  
  pthread_mutex_lock(&mutex);
  while(!done)
    pthread_cond_wait(&cond, &mutex);
  pthread_mutex_unlock(&mutex);
  pthread_join(p, NULL);
  
  printf(1, "parent finished\n");
  exit();
}
