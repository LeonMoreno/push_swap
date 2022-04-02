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
	a_node *head_b;
	int		siza;
} t_stack;

//Struct et List
a_node *createnode(int num, t_stack *stack);
void addnodefinal(t_stack *stack, int num);
a_node *ft_before(a_node *node, t_stack *stack);
void pri_stack(t_stack *stack);
void pri_stack_b(t_stack *stack);

//Commands
void ft_sa(t_stack *stack);
void ft_rra(t_stack *stack);
void ft_pb(t_stack *stack);
void ft_pa(t_stack *stack);

//Sort
void startsort(t_stack *stack);

#endif





