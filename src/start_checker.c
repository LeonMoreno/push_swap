#include "push_swap.h"

void	check_inorder(t_stack *stack)
{
	t_node	*headref;
	int		nu_before;
	int		num;

	stack->inorder = 0;
	nu_before = 0;
	headref = stack->head_a;
	num = headref->num;
	while (headref)
	{
		if (headref != stack->head_a && headref->next != NULL
			&& num > nu_before && num < headref->next->num)
			stack->inorder = 1;
		else if (headref->next != NULL)
			stack->inorder = 0;
		nu_before = num;
		headref = headref->next;
	}
}

void	check_repet(t_stack *stack)
{
	t_node	*headext;
	t_node	*headint;

	headext = stack->head_a;
	while (headext)
	{
		headint = headext->next;
		while (headint)
		{
			if (headext->num == headint->num)
				exit (7);
			headint = headint->next;
		}
		headext = headext->next;
	}
}

void	start_checker(t_stack *stack)
{
	check_inorder(stack);
	check_repet(stack);
}
