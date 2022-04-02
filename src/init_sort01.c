#include "push_swap.h"

void start_sort03(t_stack *stack)
{
	if (stack->head_a->num > stack->head_a->next->num)
	{
		ft_sa(stack);
		ft_pb(stack);
	}
	else
		ft_pb(stack);
	if (stack->head_a->num > stack->head_a->next->num)
		ft_sa(stack);
	ft_pa(stack);
}

void startsort(t_stack *stack)
{
	if (stack->siza == 3)
		start_sort03(stack);
}
