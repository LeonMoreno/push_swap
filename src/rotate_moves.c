#include "push_swap.h"

void ft_ra(t_stack *stack)
{
	a_node *s;
	a_node *t;

	s = stack->head_a;
	t = stack->head_a->next;
	while (s->next != NULL)
		s = s->next;
	stack->head_a->next = NULL;
	s->next = stack->head_a;
	stack->head_a = t;
	ft_printf("ra\n");
}
