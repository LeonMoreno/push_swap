#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/include/libft.h"

typedef struct s_node
{
	int num;
	struct s_node *next;
} a_node;

typedef struct s_stack
{
	a_node *head_a;
	int		siza;
} t_stack;

a_node *createnode(int num);
void addnodefinal(t_stack *stack, int num);
void pri_stack(t_stack *stack);
void ft_sa(t_stack *stack);
void ft_rra(t_stack *stack);
a_node *ft_before(a_node *node, t_stack *stack);

#endif





