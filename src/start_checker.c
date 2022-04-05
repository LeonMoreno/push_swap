#include "push_swap.h"

int	check_inorder(t_stack *stack)
{
	t_node	*headref;
	int		nu_before;
	int		num;
	int		inorder;

	inorder = 0;
	nu_before = 0;
	headref = stack->head_a;
	while (headref)
	{
		num = headref->num;
		if (headref != stack->head_a && headref->next != NULL
			&& num > nu_before && num < headref->next->num)
			inorder = 1;
		else if (headref->next != NULL)
			inorder = 0;
		nu_before = num;
		headref = headref->next;
	}
	//printf("Inorder = %d\n", inorder);
	return(inorder);
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
	if (check_inorder(stack))
		exit (0);
	check_repet(stack);
}
