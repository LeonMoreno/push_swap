/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:12:58 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/15 11:23:19 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	partir_a(t_stack *stack, int pivote, int len)
{
	t_node	*s;
	int		nodes;
	int		chu;

	s = stack->head_a;
	nodes = len;
	chu = 0;
	while (s && len != (nodes / 2 + nodes % 2))
	{
		if (s->num < pivote)
		{
			ft_pb(stack);
			len--;
		}
		else
		{
			ft_ra(stack);
			chu++;
		}
		s = stack->head_a;
	}
	while ((nodes / 2 + nodes % 2) != stack->siza && chu--)
		ft_rra(stack);
}

static	void	partir_b(t_stack *stack, int pivote, int len)
{
	t_node	*s;
	int		nodes;
	int		chu;

	s = stack->head_b;
	nodes = len;
	chu = 0;
	while (s && len != (nodes / 2))
	{
		if (s->num >= pivote)
		{
			ft_pa(stack);
			len--;
		}
		else
		{
			ft_rb(stack);
			chu++;
		}
	s = stack->head_b;
	}
	while (nodes / 2 + nodes % 2 != stack->sizb && chu--)
		ft_rrb(stack);
}

void	start_quicksort_b(t_stack *stack, int len)
{
	int	pivote;

	if (ft_check_inverse_order(stack, len))
	{
		while (len)
		{
			ft_pa(stack);
			len--;
		}
		return ;
	}
	if (len <= 3)
	{
		start_quicksort_3_b(stack, len);
		return ;
	}
	pivote = ft_getpivote(stack->head_b, len);
	partir_b(stack, pivote, len);
	start_quicksort_a(stack, len / 2 + len % 2);
	start_quicksort_b(stack, len / 2);
}

void	start_quicksort_a(t_stack *stack, int len)
{
	int		pivote;

	if (check_inorder(stack, len) == 1)
		return ;
	if (len <= 3)
	{
		start_quicksort_3_a(stack, len);
		return ;
	}
	pivote = ft_getpivote(stack->head_a, len);
	partir_a(stack, pivote, len);
	start_quicksort_a(stack, len / 2 + len % 2);
	start_quicksort_b(stack, len / 2);
}

void	startsort(t_stack *stack)
{
	if (stack->siza == 2)
		ft_sa(stack);
	else if (stack->siza == 3)
		start_sort_three(stack);
	else
		start_quicksort_a(stack, stack->siza);
}
