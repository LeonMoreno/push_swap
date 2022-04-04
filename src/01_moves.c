#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_node	*aux;
	t_node	*tmp;

	tmp = stack->head_a->next->next;
	aux = stack->head_a->next;
	stack->head_a->next->next = stack->head_a;
	stack->head_a->next = tmp;
	stack->head_a = aux;
	ft_printf("sa\n");
}

void	ft_pb(t_stack *stack)
{
	t_node	*tmp_a;

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
	ft_printf("pb\n");
}

void	ft_pa(t_stack *stack)
{
	t_node	*tmp_b;

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
	ft_printf("pa\n");
}
