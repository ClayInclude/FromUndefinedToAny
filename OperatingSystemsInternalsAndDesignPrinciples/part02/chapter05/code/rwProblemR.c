/**
 * rwProblemR
 * 读者优先
 * 当读者足够多时，可能会导致饥饿
 * @author Clay
 * @date 2020/12/4
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdnoreturn.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define WRITER_NUM 30
#define READER_NUM 1
#define SLEEP_TIME 1

noreturn void *reader(void *);

noreturn void *writer(void *);

noreturn void createError(char *type, int index);

noreturn void joinError(int index);

void initial(void);

void destroy(void);

int main(void)
{
    initial();

    pthread_t pool[WRITER_NUM + READER_NUM];

    for (int i = 0; i < WRITER_NUM; ++i)
    {
        pthread_t t;

        if (pthread_create(&t, NULL, writer, NULL))
        {
            createError("writer", i);
        }

        pool[i] = t;
    }

    for (int i = 0; i < READER_NUM; ++i)
    {
        pthread_t t;

        if (pthread_create(&t, NULL, reader, NULL))
        {
            createError("reader", i);
        }

        pool[i + WRITER_NUM] = t;
    }

    void *result;

    for (int i = 0; i < WRITER_NUM + READER_NUM; ++i)
    {
        if (pthread_join(pool[i], &result))
        {
            joinError(i);
        }
    }

    destroy();

    return 0;
}

sem_t sem;
pthread_mutex_t readerCountMutex;
pthread_mutex_t writeMutex;

void initial(void)
{
    sem_init(&sem, 0, 1);
    pthread_mutex_init(&readerCountMutex, NULL);
    pthread_mutex_init(&writeMutex, NULL);
}

void destroy(void)
{
    sem_destroy(&sem);
    pthread_mutex_destroy(&readerCountMutex);
    pthread_mutex_destroy(&writeMutex);
}

int x = 0;

void readX(void)
{
    printf("read x = %d\n", x);
}

void writeX(void)
{
    pthread_mutex_lock(&writeMutex);

    printf("write x = %d.\n", x = rand()); // NOLINT(cert-msc50-cpp)

    pthread_mutex_unlock(&writeMutex);
}

int readerCount = 0;

noreturn void *reader(void *_)
{
    while (true)
    {
        pthread_mutex_lock(&readerCountMutex);

        ++readerCount;

        if (readerCount == 1)
        {
            sem_wait(&sem);
        }

        pthread_mutex_unlock(&readerCountMutex);

        readX();

        pthread_mutex_lock(&readerCountMutex);

        --readerCount;

        if (readerCount == 0)
        {
            sem_post(&sem);
        }

        pthread_mutex_unlock(&readerCountMutex);

        sleep(SLEEP_TIME);
    }
}

noreturn void *writer(void *_)
{
    while (true)
    {
        sem_wait(&sem);

        writeX();

        sem_post(&sem);

        sleep(SLEEP_TIME);
    }
}

/**
 * 线程创建失败
 * @param type
 * @param index
 */
noreturn void createError(char *const type, int index)
{
    printf("type: %s, index: %d create error.\n", type, index);

    exit(1);
}

/**
 * 线程 join 失败
 * @param index
 */
noreturn void joinError(int index)
{
    printf("fail to recollect %d.\n", index);

    exit(2);
}
