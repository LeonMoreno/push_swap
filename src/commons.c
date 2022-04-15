/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:04:46 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/14 20:03:07 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_err(char *msg_err)
{
	write(2, msg_err, ft_strlen(msg_err));
	exit(1);
}

int	ft_pivote(t_node *n)
{
	int		num;
	t_node	*href;

	href = n;
	while (href->next)
		href = href->next;
	num = href->num;
	return (num);
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
	i = 0;
	ft_bublesort(arr, len);
	pivote = arr[len / 2];
	free(arr);
	return (pivote);
}
