/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:04:46 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/16 10:29:34 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_bublesort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len -1)
	{
		j = 0;
		while (j < (len - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_getpivote(t_node *n, int len)
{
	int		*arr;
	t_node	*s;
	int		i;
	int		pivote;

	i = 0;
	s = n;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	while (s && len > i)
	{
		arr[i] = s->num;
		s = s->next;
		i++;
	}
	ft_bublesort(arr, len);
	pivote = arr[len / 2];
	free(arr);
	return (pivote);
}

void	fre_lst(t_stack *stack)
{
	t_node	*h;
	t_node	*b;

	h = stack->head_a;
	while (h)
	{
		b = h;
		h = h->next;
		free(b);
	}
}

void	fre_res_split(char **res_split)
{
	int	i;

	i = 0;
	while (res_split[i])
	{
		free(res_split[i]);
		i++;
	}
	free(res_split);
}
