/**
 * Producer / Consumer Problem
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

// 生产者数量
#define PRODUCER_NUM 10
// 消费者数量
#define CONSUMER_NUM 5
// 线程休眠时间
#define SLEEP_TIME 1
// 生产概率
#define PRODUCE_RATE 0.3
// 消费概率
#define CONSUME_RATE 0.8
// 缓冲区大小
#define BUFFER_SIZE 100

// 物品类型
typedef int item;

noreturn void createError(char *type, int index);

noreturn void joinError(int index);

noreturn void *producer();

noreturn void *consumer();

void initial();

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

    return 0;
}

/**
 * 初始化随机数种子
 */
void initial()
{
    srand((unsigned int) time(NULL)); // NOLINT(cert-msc51-cpp)
}

int in = 0;
int out = 0;
int b[BUFFER_SIZE] = {0};

noreturn void produceError(char *type, int index);

/**
 * 生产
 * @param id
 * @return
 */
item produce(item id)
{
    printf("build %d\n", id);

    if (b[id])
    {
        produceError("produce same slot", in);
    }

    return id;
}

noreturn void consumeError(char *type, int index);

/**
 * 消费
 * @param id
 */
void consume(item id)
{
    if (!b[id])
    {
        consumeError("consume same slot", out);
    }
    else
    {
        b[id] = 0;
    }

    printf("use %d\n", id);
}

/**
 * 生产者
 * @return
 */
noreturn void *producer()
{
    while (true)
    {
        if (rand() / (double) RAND_MAX > PRODUCE_RATE) // NOLINT(cert-msc50-cpp)
        {
            continue;
        }

        int v = produce(in);

        if (in < 0)
        {
            produceError("index to low", in);
        }
        else if (in > BUFFER_SIZE - 1)
        {
            produceError("index to high", in);
        }

        b[in++] = v;

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
        if (rand() / (double) RAND_MAX > CONSUME_RATE) // NOLINT(cert-msc50-cpp)
        {
            continue;
        }

        if (out < 0)
        {
            consumeError("index to low", out);
        }
        else if (out > BUFFER_SIZE - 1)
        {
            consumeError("index to high", out);
        }

        int w = b[out++];

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

/**
 * 生产错误
 * @param type
 * @param index
 */
noreturn void produceError(char *const type, int index)
{
    printf("type: %s, index: %d\n", type, index);

    exit(3);
}

/**
 * 消费错误
 * @param type
 * @param index
 */
noreturn void consumeError(char *const type, int index)
{
    printf("type: %s, index: %d\n", type, index);

    exit(4);
}
