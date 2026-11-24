
#include "../push_swap.h"

void   benchmark_init(t_bench *bench, const t_stack *a, t_strategy requested)
{
    if (!a || !bench)
        return ;
    bench->disorder = compute_disorder(a);
    bench->requested_strategy = requested;
    bench->strategy = select_strategy(requested, bench->disorder);
    operation_count_init(&bench->count);
}
void benchmark_execute(t_bench *bencha, t_stack *a, t_stack *b, t_operation op)
{
    if (!bencha || !a || !b || op < OP_SA || op >= OP_COUNT)
        return ;
    if (op == OP_SA) sa(a);
    else if (op == OP_SB) sb(b);
    else if (op == OP_SS) ss(a, b);
    else if (op == OP_PA) pa(a, b);
    else if (op == OP_PB) pb(a, b);
    else if (op == OP_RA) ra(a);
    else if (op == OP_RB) rb(b);
    else if (op == OP_RR) rr(a, b);
    else if (op == OP_RRA) rra(a);
    else if (op == OP_RRB) rrb(b);
    else if (op == OP_RRR) rrr(a, b);
    operation_count_add(&bencha->count, op);
}

void benchmark_finish(const t_bench *bench)
{
    if (!bench)
        return ;
    benchmark_report(bench->disorder, bench->requested_strategy, &bench->count);
}