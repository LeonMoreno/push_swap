/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:59:55 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/15 14:15:58 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort_three(t_stack *stack)
{
	int	p;
	int	s;
	int	t;

	p = stack->head_a->num;
	s = stack->head_a->next->num;
	t = stack->head_a->next->next->num;
	if (p < s && s > t && t > p)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (p < s && s > t && t < p)
		ft_rra(stack);
	else if (p > s && s < t && t > p)
		ft_sa(stack);
	else if (p > s && s < t && t < p)
		ft_ra(stack);
	else if (p > s && s > t && t < p)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
}

static	void	p_a_bigger(t_stack *stack, int p, int s, int t)
{
	if (p > s && s > t && t < p)
	{
		ft_sa(stack);
		ft_pb(stack);
		ft_sa(stack);
		ft_pb(stack);
		ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else if (p > s && s < t && t > p)
		ft_sa(stack);
	else if (p > s && s < t && t < p)
	{
		ft_sa(stack);
		ft_pb(stack);
		ft_sa(stack);
		ft_pa(stack);
	}
}

static	void	p_a_smaller(t_stack *stack, int p, int s, int t)
{
	if (p < s && s > t && t > p)
	{
		ft_pb(stack);
		ft_sa(stack);
		ft_pa(stack);
	}
	else if (p < s && s > t && t < p)
	{
		ft_pb(stack);
		ft_sa(stack);
		ft_pa(stack);
		ft_sa(stack);
	}
}

void	start_quicksort_3_a(t_stack *stack, int len)
{
	int	p;
	int	s;
	int	t;

	if (len == 2)
	{
		if (stack->head_a->num > stack->head_a->next->num)
			ft_sa(stack);
	}
	else if (len == 3 && stack->siza == 3)
		start_sort_three(stack);
	else if (len == 3)
	{
		p = stack->head_a->num;
		s = stack->head_a->next->num;
		t = stack->head_a->next->next->num;
		p_a_bigger(stack, p, s, t);
		p_a_smaller(stack, p, s, t);
	}
}
