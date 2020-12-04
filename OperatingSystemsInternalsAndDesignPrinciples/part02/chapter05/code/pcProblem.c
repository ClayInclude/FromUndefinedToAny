/**
 * Producer / Consumer Problem
 * toFix
 * @author Clay
 * @date 2020/12/3
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdnoreturn.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// 生产者数量
#define PRODUCER_NUM 10
// 消费者数量
#define CONSUMER_NUM 5
// 线程休眠时间
#define SLEEP_TIME 1
// 缓冲区大小
#define BUFFER_SIZE 100

// 物品类型
typedef int item;

noreturn void createError(char *type, int index);

noreturn void joinError(int index);

noreturn void *producer();

noreturn void *consumer();

void initial();

void destroy();

pthread_mutex_t s;
sem_t n;

int main(void)
{
    initial();

    pthread_t threadPool[PRODUCER_NUM + CONSUMER_NUM];

    for (int i = 0; i < PRODUCER_NUM; ++i)
    {
        pthread_t p;

        if (pthread_create(&p, NULL, producer, NULL))
        {
            createError("producer", i);
        }

        threadPool[i] = p;
    }

    for (int i = 0; i < CONSUMER_NUM; ++i)
    {
        pthread_t p;

        if (pthread_create(&p, NULL, consumer, NULL))
        {
            createError("consumer", i);
        }

        threadPool[i + PRODUCER_NUM] = p;
    }

    void *result;

    for (int i = 0; i < PRODUCER_NUM + CONSUMER_NUM; ++i)
    {
        if (pthread_join(threadPool[i], &result))
        {
            joinError(i);
        }
    }

    destroy();

    return 0;
}

/**
 * 初始化
 */
void initial()
{
    srand((unsigned int) time(NULL)); // NOLINT(cert-msc51-cpp)

    pthread_mutex_init(&s, NULL);
    sem_init(&n, 0, 0);
}

void destroy()
{
    pthread_mutex_destroy(&s);
    sem_destroy(&n);
}

int in = 0;
int out = 0;

item b[BUFFER_SIZE] = {0};

/**
 * 生产
 * @param id
 * @return
 */
item produce()
{
    static item index = 0;

    printf("build %d\n", ++index);

    return index;
}

void append(item index)
{
    printf("append %d\n", index);

    b[in] = index;

    in = (in + 1) % BUFFER_SIZE;
}

item take()
{
    item index = out;
    printf("take %d\n", index + 1);

    item w = b[index];

    b[index] = 0;

    out = (out + 1) % BUFFER_SIZE;

    return w;
}

/**
 * 消费
 * @param id
 */
void consume(item index)
{
    printf("use %d\n", index);
}

/**
 * 生产者
 * @return
 */
noreturn void *producer()
{
    while (true)
    {
        pthread_mutex_lock(&s);

        append(produce());

        pthread_mutex_unlock(&s);
        sem_post(&n);

        sleep(SLEEP_TIME);
    }
}

/**
 * 消费者
 * @return
 */
noreturn void *consumer()
{
    while (true)
    {
        sem_wait(&n);
        pthread_mutex_lock(&s);

        item w = take();

        pthread_mutex_unlock(&s);

        consume(w);

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
