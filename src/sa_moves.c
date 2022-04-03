#include "push_swap.h"

void ft_sa(t_stack *stack)
{
	a_node *aux;
	a_node *tmp;

	tmp = stack->head_a->next->next;
	aux = stack->head_a->next;
	stack->head_a->next->next = stack->head_a;
	stack->head_a->next = tmp;
	stack->head_a = aux;
	printf("sa\n");
}

