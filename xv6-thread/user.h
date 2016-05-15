struct stat;
struct rtcdate;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

int date(struct rtcdate*);
int clone(void(*func)(void*), void* arg, void* stack);
int join(int threadId, void** childStack);
void threadSleep(newpthread_mutex_t *mutex);
void threadWake(int threadId);
// ulib.c
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

int pthread_create(newpthread_t* thread, newpthread_attr_t *attr, void(*func)(void*), void* arg);
int pthread_join(newpthread_t thread, void **retval);
void pthread_mutex_init(newpthread_mutex_t *mutex);
void pthread_mutex_lock(newpthread_mutex_t *mutex);
void pthread_mutex_unlock(newpthread_mutex_t *mutex);

typedef struct newpthread_cond{
  int threadId;
  struct newpthread_cond *next;
}newpthread_cond_t;

typedef struct newpthread_sem{
	int value;
	newpthread_cond_t cond;
	newpthread_mutex_t mutex;
}newpthread_sem_t;

void pthread_cond_init(newpthread_cond_t *cond);
void pthread_cond_wait(newpthread_cond_t *cond, newpthread_mutex_t *mutex);
void pthread_cond_signal(newpthread_cond_t *cond);

void pthread_sem_post(newpthread_sem_t *sem);
void pthread_sem_wait(newpthread_sem_t *sem);
void pthread_sem_init(newpthread_sem_t *sem, int flag, int value);