/**
 * Job
 * @author Clay
 * @date 2021/1/29
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include "Job.h"

#define MAX_JOB 128

struct JobInfo jobs[MAX_JOB];

int jobIndex = 0;
int jid = 1000;

void initJob()
{
    memset(jobs, 0, sizeof(jobs));
}

void addJob(pid_t pid, char *cmdline, bool inBackground)
{
    struct JobInfo *p = jobs + jobIndex++;

    p->pid = pid;
    strcpy(p->cmdline, cmdline);
    p->inBackground = inBackground;
    p->status = JOB_RUNNING;
    p->using = true;
    p->jid = jid++;
}

void stopJob(pid_t pid)
{

}

void restartJob(pid_t pid)
{

}

int getJidByArg(char *arg)
{
    return (int) strtol(arg + 1, NULL, 10);
}

int getJid(pid_t pid)
{
    for (size_t i = 0; i < MAX_JOB; ++i)
    {
        struct JobInfo job = jobs[i];

        if (!job.using)
        {
            continue;
        }

        if (job.pid == pid)
        {
            return job.jid;
        }
    }

    return 0;
}

pid_t getPid(int jid)
{
    for (size_t i = 0; i < MAX_JOB; ++i)
    {
        struct JobInfo job = jobs[i];

        if (!job.using)
        {
            continue;
        }

        if (job.jid == jid)
        {
            return job.pid;
        }
    }

    return 0;
}

struct JobInfo *getJobPtr(pid_t pid)
{
    for (size_t i = 0; i < MAX_JOB; ++i)
    {
        struct JobInfo job = jobs[i];

        if (!job.using)
        {
            continue;
        }

        if (job.pid == pid)
        {
            return jobs + i;
        }
    }

    return NULL;
}

void printJob()
{
    for (size_t i = 0; i < MAX_JOB; ++i)
    {
        struct JobInfo job = jobs[i];

        if (!job.using)
        {
            continue;
        }

        printf("[%d] %d %s \t %s\n", job.jid, job.pid, job.status == JOB_RUNNING ? "Running" : "Stopped", job.cmdline);
    }
}
