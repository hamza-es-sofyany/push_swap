
#include "../push_swap.h"

t_strategy select_strategy(t_strategy requested, double disorder)
{
    if (requested != STRATEGY_ADAPTIVE)
        return (requested);
    if (disorder < 0.2)
        return (STRATEGY_SIMPLE);
    if (disorder < 0.5)
        return (STRATEGY_MEDIUM);
    return (STRATEGY_COMPLEX);
}
#include <stdio.h>

int main(void)
{
    t_strategy requested[8] = {
        STRATEGY_SIMPLE,
        STRATEGY_MEDIUM,
        STRATEGY_COMPLEX,
        STRATEGY_ADAPTIVE,
        STRATEGY_ADAPTIVE,
        STRATEGY_ADAPTIVE,
        STRATEGY_ADAPTIVE,
        STRATEGY_ADAPTIVE
    };
    double disorder[8] = {
        0.9, 0.1, 0.0, 0.19,
        0.2, 0.49, 0.5, 0.9
    };
    t_strategy expected[8] = {
        STRATEGY_SIMPLE,
        STRATEGY_MEDIUM,
        STRATEGY_COMPLEX,
        STRATEGY_SIMPLE,
        STRATEGY_MEDIUM,
        STRATEGY_MEDIUM,
        STRATEGY_COMPLEX,
        STRATEGY_COMPLEX
    };
    int i;
    int passed;

    i = 0;
    passed = 0;
    while (i < 8)
    {
        if (select_strategy(requested[i], disorder[i]) == expected[i])
        {
            printf("TEST %02d: PASS\n", i + 1);
            passed++;
        }
        else
            printf("TEST %02d: FAIL\n", i + 1);
        i++;
    }
    printf("\nRESULT: %d/8 passed\n", passed);
    return (passed == 8 ? 0 : 1);
}