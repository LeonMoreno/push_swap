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
t_node	*ft_before(t_node *node, t_stack *stack);
void	pri_stack(t_stack *stack);
void	pri_stack_b(t_stack *stack);

//Commands
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);

//Sort
void	startsort(t_stack *stack);
void start_quicksort_a(t_stack *stack, int len);

//Utils
void	start_checker(t_stack *stack);
int ft_lenlst(t_node *n);
int ft_pivote(t_node *n);
int	check_inorder(t_stack *stack);
int	ft_mayor(t_node *n);

#endif
