/* crude testing framework
 */

struct TestInfo
{
    int (*setup)();
    int (*teardown)();
};

int runtest(struct TestInfo testinfo, int (*test)());

int runsuite(struct TestInfo testinfo, int (*tests[])(),
        unsigned int numtests);

int runproc(int (*func)());
