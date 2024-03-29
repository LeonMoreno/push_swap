/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:04:40 by lmoreno           #+#    #+#             */
/*   Updated: 2022/04/16 11:04:43 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*head_b;
	int		siza;
	int		sizb;
}	t_stack;

//Struct et List
t_node	*createnode(int num, t_stack *stack);
void	addnodefinal(t_stack *stack, int num);
t_node	*ft_before(t_node *node, t_node *stack);
void	print_stack(t_node *s);

//Commands
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);

//Sort
void	startsort(t_stack *stack);
void	start_quicksort_a(t_stack *stack, int len);
void	start_quicksort_b(t_stack *stack, int len);
void	start_quicksort_3_a(t_stack *stack, int len);
void	start_quicksort_3_b(t_stack *stack, int len);
void	start_sort_three(t_stack *stack);

//Utils
void	start_checker(t_stack *stack);
int		ft_lenlst(t_node *n);
int		check_inorder(t_stack *stack, int len);
int		ft_check_inverse_order(t_stack *stack, int len);
int		ft_getpivote(t_node *n, int len);
void	ft_bublesort(int *arr, int len);
void	fre_lst(t_stack *stack);
void	fre_res_split(char **res_split);
void	msg_err(void);

#endif
