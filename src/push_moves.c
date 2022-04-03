
#include "push_swap.h"

void ft_pb(t_stack *stack)
{
	a_node *tmp_a;

	tmp_a = stack->head_a;
	stack->head_a = stack->head_a->next;

	if (stack->head_b == NULL)
	{
		tmp_a->next = NULL;
		stack->head_b = tmp_a;
	}
	else
	{
		tmp_a->next = stack->head_b;
		stack->head_b = tmp_a;
	}
	printf("pb\n");
}

void ft_pa(t_stack *stack)
{
	a_node *tmp_b;

	tmp_b = stack->head_b;
	stack->head_b = stack->head_b->next;
	if (stack->head_a == NULL)
	{
		tmp_b->next = NULL;
		stack->head_a = tmp_b;
	}
	else
	{
		tmp_b->next = stack->head_a;
		stack->head_a = tmp_b;
	}
	printf("pa\n");
}
