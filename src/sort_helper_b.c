/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:39:36 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/14 19:39:04 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort_three_b(t_stack *stack, int p, int s, int t)
{
	if (p < s && s > t && t > p)
		ft_rb(stack);
	else if (p < s && s < t && t > p)
	{
		ft_rb(stack);
		ft_sb(stack);
	}
	else if (p > s && s < t && t < p)
	{
		ft_rrb(stack);
		ft_sb(stack);
	}
	else if (p > s && s < t && t > p)
		ft_rrb(stack);
	else if (p < s && s > t && t < p)
		ft_sb(stack);
	ft_pa(stack);
	ft_pa(stack);
	ft_pa(stack);
}

void	p_b_bigger(t_stack *stack, int p, int s, int t)
{
	if (p > s && s < t && t < p)
	{
		ft_pa(stack);
		ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else if (p > s && s < t && t > p)
	{
		ft_rb(stack);
		ft_sb(stack);
		ft_pa(stack);
		ft_rrb(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else if (p > s && s > t && t < p)
	{
		ft_pa(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
}

void	p_b_smaller(t_stack *stack, int p, int s, int t)
{
	if (p < s && s > t && t > p)
	{
		ft_sb(stack);
		ft_pa(stack);
		ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else if (p < s && s < t && t > p)
	{
		ft_rb(stack);
		ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
		ft_rrb(stack);
		ft_pa(stack);
	}
	else if (p < s && s > t && t < p)
	{
		ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
}

void	p_len(t_stack *stack, int p, int s, int t)
{
	p_b_bigger(stack, p, s, t);
	p_b_smaller(stack, p, s, t);
}

void	start_quicksort_3_b(t_stack *stack, int len)
{
	int	p;
	int	s;
	int	t;

	if (len == 1)
		ft_pa(stack);
	else if (len == 2)
	{
		if (stack->head_b->num < stack->head_b->next->num)
			ft_sb(stack);
		ft_pa(stack);
		ft_pa(stack);
	}
	else if (len == 3 || stack->sizb == 3)
	{
		p = stack->head_b->num;
		s = stack->head_b->next->num;
		t = stack->head_b->next->next->num;
		if (len == 3 && stack->sizb == 3)
			start_sort_three_b(stack, p, s, t);
		else if (len == 3)
			p_len(stack, p, s, t);
	}
}
