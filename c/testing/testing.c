#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "testing.h"

int runproc(int (*func)())
{
    int commpipe[2];
    pid_t pid;
    int ret = -1;

    if (pipe(commpipe) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        return 1;
    }

    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        return 1;
    }
    else if (pid > 0)  /* parent process */
    {
        close(commpipe[1]);
        wait(NULL);
        read(commpipe[0], &ret, sizeof(ret));

        if (ret < 0)
        {
            fprintf(stderr, "did not get result from child\n");
            return 1;
        }

        close(commpipe[0]);
    }
    else  /* child process */
    {
        close(commpipe[0]);

        ret = func();
        write(commpipe[1], &ret, sizeof(ret));

        close(commpipe[1]);
        _exit(0);
    }

    return ret;
}

int runtest(struct TestInfo testinfo, int (*test)())
{
    int result;

    if (runproc(testinfo.setup) != 0)
    {
        return 1;
    }

    result = runproc(test);

    if (runproc(testinfo.teardown) != 0)
    {
        return 1;
    }

    return result;
}

int runsuite(struct TestInfo testinfo, int (*tests[])(),
        unsigned int numtests)
{
    int overallresult = 0;

    for(int i = 0; i < numtests; i++)
    {
        overallresult = runtest(testinfo, tests[i]);
    }

    return overallresult;
}
