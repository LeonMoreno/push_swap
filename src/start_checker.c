/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:01:39 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/15 15:44:22 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int  ft_check_inverse_order(t_stack *stack)
// {
// 	t_node *s;
// 	int before;
// 	int num;
// 	int ordes;

// 	ordes = 0;
// 	before = stack->head_b->num;
// 	s = stack->head_b;
// 	if (stack->sizb == 2 && stack->head_b->num > stack->head_b->next->num)
// 		ordes = 1;
// 	else
// 	{
// 		while(s)
// 		{
// 			num = s->num;
// 			if (s != stack->head_b && s->next != NULL
// 				&& num < before && num > s->next->num)
// 				{
// 					ordes = 1;
// 				}

// 			else if (s != stack->head_b  && s->next != NULL)
// 				{
// 					ordes  = 0;
// 					break;
// 				}
// 			before = num;
// 			s = s->next;
// 		}
// 	}
// 	//printf("ordes = %d\n", ordes);
// 	return (ordes);
// }

// int	check_inorder(t_stack *stack)
// {
// 	t_node	*headref;
// 	int		nu_before;
// 	int		num;
// 	int		inorder;

// 	inorder = 0;
// 	nu_before = 0;
// 	headref = stack->head_a;
// 	if (stack->siza == 2 && headref->num < headref->next->num)
// 		inorder = 1;
// 	else
// 	{
// 		while (headref)
// 		{
// 			num = headref->num;
// 			if (headref != stack->head_a && headref->next != NULL
// 				&& num > nu_before && num < headref->next->num)
// 				{
// 					inorder = 1;
// 				}

// 			else if (headref != stack->head_a && headref->next != NULL)
// 			{
// 				inorder = 0;
// 				break;
// 			}
// 			nu_before = num;
// 			headref = headref->next;
// 		}
// 	}
// 	//printf("INOrder = %d\n", inorder);
// 	return(inorder);
// }

int	check_inorder(t_stack *stack, int len)
{
	t_node	*h;
	int		num_bef;

	h = stack->head_a;
	while (h && len)
	{
		if (h != stack->head_a && num_bef > h->num)
			return (0);
		num_bef = h->num;
		h = h->next;
		len--;
	}
	return (1);
}

int	ft_check_inverse_order(t_stack *stack, int len)
{
	t_node	*h;
	int		num_bef;

	h = stack->head_a;
	while (h && len)
	{
		if (h != stack->head_a && num_bef < h->num)
			return (0);
		num_bef = h->num;
		h = h->next;
		len--;
	}
	return (1);
}

static	void	check_repet(t_stack *stack)
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
			{
				ft_putstr_fd("Error\n", 2);
				exit (7);
			}
			headint = headint->next;
		}
		headext = headext->next;
	}
}

void	start_checker(t_stack *stack)
{
	if (check_inorder(stack, stack->siza))
		exit (0);
	check_repet(stack);
}
