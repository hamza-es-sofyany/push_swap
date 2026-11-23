
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
