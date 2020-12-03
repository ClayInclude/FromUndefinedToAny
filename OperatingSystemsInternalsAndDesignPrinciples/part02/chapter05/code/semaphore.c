/**
 * semaphore
 * @author Clay
 * @date 2020/12/3
 */

#include <stdnoreturn.h>
#include <stdbool.h>

struct QueueType
{
    bool isEmpty;
};

struct Semaphore
{
    int count;

    struct QueueType queue;
};

struct BinarySemaphore
{
    enum
    {
        ZERO,

        ONE
    } value;

    struct QueueType queue;
};

void semWait(struct Semaphore s)
{
    --s.count;

    if (s.count < 0)
    {
        // block this process in s.queue
    }
}

void semSignal(struct Semaphore s)
{
    ++s.count;

    if (s.count >= 0)
    {
        // remove a process P from s.queue, place process on ready list
    }
}

void semWaitB(struct BinarySemaphore s)
{
    if (s.value == ONE)
    {
        s.value = ZERO;
    }
    else
    {
        // block this process in s.queue
    }
}

void semSignalB(struct BinarySemaphore s)
{
    if (s.queue.isEmpty)
    {
        s.value = ONE;
    }
    else
    {
        // remove a process P from s.queue, place process on ready list
    }
}

struct Semaphore s = {.count = 1};

noreturn void p(int i)
{
    while (true)
    {
        semWait(s);

        // critical section

        semSignal(s);

        // remainder
    }
}
