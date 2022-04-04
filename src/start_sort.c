#include "push_swap.h"

	/* Mi idea inicial
	 * if (stack->head_a->num > stack->head_a->next->num)
	{
		ft_sa(stack);
		ft_pb(stack);
	}
	else
		ft_pb(stack);
	if (stack->head_a->num > stack->head_a->next->num)
		ft_sa(stack);
	ft_pa(stack);*/
void	start_sort_three(t_stack *stack)
{
	int	p;
	int	s;
	int	t;

	p = stack->head_a->num;
	s = stack->head_a->next->num;
	t = stack->head_a->next->next->num;
	if (p < s && s > t && t > p)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (p < s && s > t && t < p)
		ft_rra(stack);
	else if (p > s && s < t && t > p)
		ft_sa(stack);
	else if (p > s && s < t && t < p)
		ft_ra(stack);
	else if (p > s && s > t && t < p)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
}

void start_quicksort(t_stack *stack)
{
	int pivote;
	t_node *href;

	href = stack->head_a;
	pivote = ft_pivote(stack);
	while (href)
	{
		printf("Entro\n");
		if (href->num < pivote)
			{
				ft_pb(stack);
			}
		else if (href->num > pivote)
			ft_ra(stack);
		href = href->next;
	}
}

void	startsort(t_stack *stack)
{
	if (stack->siza == 3)
		start_sort_three(stack);
	if (stack->siza > 3)
		start_quicksort(stack);
}
