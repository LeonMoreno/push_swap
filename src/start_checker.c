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
	if (stack->siza == 2 && headref->num < headref->next->num)
		inorder = 1;
	else
	{
		while (headref)
		{
			num = headref->num;
			if (headref != stack->head_a && headref->next != NULL
				&& num > nu_before && num < headref->next->num)
				{
					//printf("IF before = %d -- num = % d -- next = %d\n", nu_before, num, headref->next->num);
					inorder = 1;
				}

			else if (headref != stack->head_a && headref->next != NULL)
			{
				//printf("ELSE before = %d -- num = % d -- next = %d\n", nu_before, num, headref->next->num);
				inorder = 0;
				break;
			}
			nu_before = num;
			headref = headref->next;
		}
	}
	//printf("INOrder = %d\n", inorder);
	return(inorder);
}

int  ft_check_inverse_order(t_stack *stack)
{
	t_node *s;
	int before;
	int num;
	int ordes;

	ordes = 0;
	before = stack->head_b->num;
	s = stack->head_b;
	if (stack->sizb == 2 && stack->head_b->num > stack->head_b->next->num)
		ordes = 1;
	else
	{
		while(s)
		{
			num = s->num;
			if (s != stack->head_b && s->next != NULL
				&& num < before && num > s->next->num)
				{
				//	printf("IF before = %d -- num = % d -- next = %d\n", before, num, s->next->num);
					ordes = 1;
				}

			else if (s != stack->head_b  && s->next != NULL)
				{
				//	printf("ELSE before = %d -- num = % d -- next = %d\n", before, num, s->next->num);
					ordes  = 0;
					break;
				}
			before = num;
			s = s->next;
		}
	}
	//printf("ordes = %d\n", ordes);
	return (ordes);
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

int	ft_mayor(t_node *n)
{
	t_node	*h;
	int mayor;

	h = n;
	mayor = -2147483648;
	while (h)
	{
		if (h->num > mayor)
			mayor = h->num;
		h = h->next;
	}

	return (mayor);
}

void	start_checker(t_stack *stack)
{
	if (check_inorder(stack))
		exit (0);
	//ft_check_inverse_order(stack);
	check_repet(stack);
}
