#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
    int pid, exitCode;
    int childPid = 0;
    printf(0, "\n#### Starting testing Part A, B using fork, exit, wait ####\n");

    // First Part A, B test with exit code 0
    // Use fork to test for the exit and wait function
    pid = fork();
    // Child process
    if (pid == 0)
    {
        printf(0, "\n *** Hello, greeting from child process with PID %d! Exiting now with exit 0 status!\n", getpid());
        sleep(100);
        exit(0);
    }
    else if (pid > 0)
    {
        childPid = wait(&exitCode);
        printf(0, "\n && Hello, Parent here! My child with PID %d just exit with status code %d, looks like he's happy now :)\n", childPid, exitCode);
    }

    // Second Part A, B test with exit code -1
    // Use fork to test for the exit and wait function
    pid = fork();
    // Child process
    if (pid == 0)
    {
        printf(0, "\n *** Hello, greeting from child process with PID %d! Exiting now with exit -1 status!\n", getpid());
        sleep(100);
        exit(-1);
    }
    else if (pid > 0)
    {
        childPid = wait(&exitCode);
        printf(0, "\n && Hello, Parent here! My child with PID %d just exit with status code %d, looks like he's a little sad now :(\n", childPid, exitCode);
    }
    else
    {
        childPid = 0;
        printf(0, "\n I guess fork error\n");
    }

    // Part C test
    printf(0, "\n#### Starting testing Part C using fork, waitpid ####\n");

    pid = fork();
    if (pid == 0)
    {
        printf(0, "\n *** Hello, greeting from child process with PID %d! Exiting now with exit 0 status!\n", getpid());
        sleep(100);
        exit(0);
    }
    else if (pid > 0)
    {
        childPid = waitpid(pid, &exitCode, 0);
        printf(0, "\n && Hello, Parent here! A child with PID %d just exit with status code %d, looks like he's happy :)\n", childPid, exitCode);
    }

    pid = fork();
    if (pid == 0)
    {
        printf(0, "\n *** Hello, greeting from child process with PID %d! Exiting now with exit -1 status!\n", getpid());
        sleep(100);
        exit(-1);
    }
    else if (pid > 0)
    {
        childPid = waitpid(pid, &exitCode, 0);
        printf(0, "\n && Hello, Parent here! A child with PID %d just exit with status code %d, looks like he's sad now :<\n", childPid, exitCode);
    }

    // End of test
    exit(0);
}