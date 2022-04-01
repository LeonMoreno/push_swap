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
}

void ft_rra(t_stack *stack)
{
	a_node *headref;
	a_node *beforef;
	a_node *tmp;

	tmp = stack->head_a->next;
	headref = stack->head_a;
	while (headref->next != NULL)
		headref = headref->next;
	beforef = ft_before(headref, stack);
	stack->head_a->next = NULL;
	beforef->next = stack->head_a;
	stack->head_a = headref;
	headref->next = tmp;
}

a_node *ft_before(a_node *node, t_stack *stack)
{
	a_node *headref;

	headref = stack->head_a;
	while (headref && node->num != headref->next->num)
		headref = headref->next;
	return (headref);
}
		
	

