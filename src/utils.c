
#include "push_swap.h"

a_node *ft_before(a_node *node, t_stack *stack)
{
	a_node *headref;

	headref = stack->head_a;
	while (headref && node->num != headref->next->num)
		headref = headref->next;
	return (headref);
}
