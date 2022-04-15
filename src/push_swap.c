/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:49:16 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/15 15:44:40 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	parser_argv(char **argv)
{
	int	i;
	int	spa;

	i = 0;
	spa = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			return (1);
			i++;
	}
	return (0);
}

static	t_stack	start_stack(char **argv)
{
	t_stack	stack;
	char	**res_split;
	int		res_spa;
	int		i;
	long	int		num;

	stack.siza = 0;
	stack.sizb = 0;
	stack.head_a = NULL;
	stack.head_b = NULL;
	res_spa = parser_argv(argv);
	if (res_spa == 0)
	{
		i = 1;
		while (argv[i])
		{
			num = ft_atoi(argv[i]);
			if (num < INT_MIN || num > INT_MAX)
				printf("Mayor BRAVO\n");
			addnodefinal(&stack, num);
			i++;
		}

	}
	else
	{
		i = 0;
		res_split = ft_split(argv[1], ' ');
		while (res_split[i])
			addnodefinal(&stack, ft_atoi(res_split[i++]));
		fre_res_split(res_split);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc >= 2)
	{
		stack = start_stack(argv);
		start_checker(&stack);
		startsort(&stack);
		print_stack(stack.head_a);
		fre_lst(&stack);
	}
	return (0);
}
