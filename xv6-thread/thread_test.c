#include "types.h"
#include "user.h"
#include "x86.h"

#define NULL 0

newpthread_mutex_t mutex;

void thread(void* arg){
  pthread_mutex_lock(&mutex);
  printf(1, "This is thread %d\n", (int)arg);
  pthread_mutex_unlock(&mutex);
  exit();
}

int main(){
  int i;
  newpthread_t p[5];
  pthread_mutex_init(&mutex);
  for(i=0; i<5; i++)
    pthread_create(&p[i], NULL, thread, (void*)i);
  for(i=0; i<5; i++)
    pthread_join(p[i], NULL);
  exit();
}
