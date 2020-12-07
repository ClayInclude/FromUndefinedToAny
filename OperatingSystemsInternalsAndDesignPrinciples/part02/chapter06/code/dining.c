/**
 * dining
 * @author Clay
 * @date 2020/12/7
 */

#include <stdbool.h>
#include <semaphore.h>
#include <stdnoreturn.h>

sem_t fork[5];
sem_t room;

void eat(int i)
{

}

noreturn void philosopher(int i)
{
    while (true)
    {
        sem_wait(room);
        sem_wait(fork[i]);
        sem_wait(fork[(i + 1) % 5]);

        eat(i);

        sem_post(fork[(i + 1) % 5]);
        sem_post(fork[i]);
        sem_post(room);
    }
}
