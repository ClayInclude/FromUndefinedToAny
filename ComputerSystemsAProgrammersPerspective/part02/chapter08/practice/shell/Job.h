/**
 * Job
 * @author Clay
 * @date 2021/1/29
 */

#ifndef FROM_UNDEFINED_TO_ANY_JOB_H
#define FROM_UNDEFINED_TO_ANY_JOB_H

#define MAX_CHARS 1280

enum JOB_STATUS
{
    JOB_RUNNING,
    JOB_STOPPED
};

struct JobInfo
{
    bool using;

    bool inBackground;

    char cmdline[MAX_CHARS];

    enum JOB_STATUS status;

    int jid;

    int pid;
};

void initJob();

void addJob(pid_t pid, char *cmdline, bool inBackground);

void stopJob(pid_t pid);

void restartJob(pid_t pid);

int getJidByArg(char *arg);

int getJid(pid_t pid);

pid_t getPid(int jid);

struct JobInfo *getJobPtr(pid_t pid);

void printJob();

#endif //FROM_UNDEFINED_TO_ANY_JOB_H
