#include "push_swap.h"

void	ft_ra(t_stack *stack)
{
	t_node	*s;
	t_node	*t;

	s = stack->head_a;
	t = stack->head_a->next;
	while (s->next != NULL)
		s = s->next;
	stack->head_a->next = NULL;
	s->next = stack->head_a;
	stack->head_a = t;
	ft_printf("ra\n");
}

void	ft_rb(t_stack *stack)
{
	t_node	*s;
	t_node	*t;

	s = stack->head_b;
	t = stack->head_b->next;
	while (s->next != NULL)
		s = s->next;
	stack->head_b->next = NULL;
	s->next = stack->head_b;
	stack->head_b = t;
	ft_printf("rb\n");
}

void	ft_rra(t_stack *stack)
{
	t_node	*headref;
	t_node	*beforef;
	t_node	*tmp;

	tmp = stack->head_a;
	headref = stack->head_a;
	while (headref->next != NULL)
		headref = headref->next;
	beforef = ft_before(headref, stack->head_a);
	beforef->next = NULL;
	stack->head_a = headref;
	headref->next = tmp;
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *stack)
{
	t_node	*headref;
	t_node	*beforef;
	t_node	*tmp;

	tmp = stack->head_b;
	headref = stack->head_b;
	//pri_stack_b(stack);
	while (headref->next != NULL)
		headref = headref->next;
	beforef = ft_before(headref, stack->head_b);
	beforef->next = NULL;
	stack->head_b = headref;
	headref->next = tmp;
	ft_printf("rrb\n");
}
