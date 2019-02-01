#include <assert.h>
#include "testing.h"

int setup(void)
{
    return 0;
}

int failsetup(void)
{
    return 1;
}

int teardown(void)
{
    return 0;
}

int failteardown(void)
{
    return 1;
}

int passtest1(void)
{
    return 0;
}

int passtest2(void)
{
    return 0;
}

int failtest(void)
{
    return 1;
}


int main(int argc, char **argv)
{
    int result;
    struct TestInfo ti;

    ti.setup = setup;
    ti.teardown = teardown;

    result = runtest(ti, failtest);
    assert(result == 1);

    result = runtest(ti, passtest1);
    assert(result == 0);

    int (*passing_suite[2])() = {passtest1, passtest2};
    result = runsuite(ti, passing_suite, 2);
    assert(result == 0);

    int (*failing_suite[3])() = {passtest1, passtest2, failtest};
    result = runsuite(ti, failing_suite, 3);
    assert(result == 1);

    ti.setup = failsetup;
    result = runtest(ti, passtest1);
    assert(result == 1);

    ti.setup = setup;
    ti.teardown = failteardown;
    result = runtest(ti, passtest1);
    assert(result == 1);

    return 0;
}
