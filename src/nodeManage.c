/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeManage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:06:03 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/14 17:12:16 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addnodefinal(t_stack *stack, int num)
{
	t_node	*node;
	t_node	*aux;

	node = createnode(num, stack);
	if (stack->head_a == NULL)
		stack->head_a = node;
	else
	{
		aux = stack->head_a;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}
}

t_node	*createnode(int num, t_stack *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new != NULL)
	{
		stack->siza += 1;
		new->num = num;
		new->next = NULL;
	}
	return (new);
}

void	print_stack(t_node *s)
{
	t_node	*headref;

	headref = s;
	while (headref)
	{
		printf ("%d\n", headref->num);
		headref = headref->next;
	}
}

t_node	*ft_before(t_node *node, t_node *stack)
{
	t_node	*headref;

	headref = stack;
	while (headref && node->num != headref->next->num)
		headref = headref->next;
	return (headref);
}

int	ft_lenlst(t_node *n)
{
	t_node	*href;
	int		i;

	i = 0;
	href = n;
	while (href)
	{
		href = href->next;
		i++;
	}
	return (i);
}
