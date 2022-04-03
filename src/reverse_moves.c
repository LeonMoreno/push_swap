#include "push_swap.h"

void ft_rra(t_stack *stack)
{
	a_node *headref;
	a_node *beforef;
	a_node *tmp;

	tmp = stack->head_a;
	headref = stack->head_a;
	while (headref->next != NULL)
		headref = headref->next;
	beforef = ft_before(headref, stack);
	beforef->next = NULL;
	stack->head_a = headref;
	headref->next = tmp;
	printf("rra\n");
}
