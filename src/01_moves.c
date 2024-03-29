/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:04:10 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/15 14:32:42 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_node	*aux;
	t_node	*tmp;

	tmp = stack->head_a->next->next;
	aux = stack->head_a->next;
	stack->head_a->next->next = stack->head_a;
	stack->head_a->next = tmp;
	stack->head_a = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *stack)
{
	t_node	*aux;
	t_node	*tmp;

	tmp = stack->head_b->next->next;
	aux = stack->head_b->next;
	stack->head_b->next->next = stack->head_b;
	stack->head_b->next = tmp;
	stack->head_b = aux;
	ft_putstr_fd("sb\n", 1);
}

void	ft_pb(t_stack *stack)
{
	t_node	*tmp_a;

	tmp_a = stack->head_a;
	stack->head_a = stack->head_a->next;
	stack->siza--;
	stack->sizb++;
	if (stack->head_b == NULL)
	{
		tmp_a->next = NULL;
		stack->head_b = tmp_a;
	}
	else
	{
		tmp_a->next = stack->head_b;
		stack->head_b = tmp_a;
	}
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack *stack)
{
	t_node	*tmp_b;

	tmp_b = stack->head_b;
	stack->sizb--;
	stack->siza++;
	stack->head_b = stack->head_b->next;
	if (stack->head_a == NULL)
	{
		tmp_b->next = NULL;
		stack->head_a = tmp_b;
	}
	else
	{
		tmp_b->next = stack->head_a;
		stack->head_a = tmp_b;
	}
	ft_putstr_fd("pa\n", 1);
}
