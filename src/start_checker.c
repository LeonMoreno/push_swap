#include "push_swap.h"

void check_inorder(t_stack *stack)
{
	a_node *headref;
	int	before;

	stack->inorder = 0;
	before = 0;
	headref = stack->head_a;
	while (headref)
	{
		if (headref != stack->head_a && headref->num  == before + 1)
			stack->inorder = 1;
		else
			stack->inorder = 0;
		before = headref->num;
		headref = headref->next;
	}
}

void check_repet(t_stack *stack)
{
	a_node *headext;
	a_node *headint;

	headext = stack->head_a;
	while(headext)
	{
		headint = headext->next;
		while(headint)
		{
			if (headext->num == headint->num)
				exit (7);
			headint = headint->next;
		}
		headext = headext->next;
	}
}

void start_checker(t_stack *stack)
{
	check_inorder(stack);
	check_repet(stack);
}
