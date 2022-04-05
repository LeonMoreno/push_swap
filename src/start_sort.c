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

	if (((ft_lenlst(stack->head_a)) == 3))
	{
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
	else if ((ft_lenlst(stack->head_a)) == 2)
	{
		p = stack->head_a->num;
		s = stack->head_a->next->num;

		if (p > s)
			ft_sa(stack);

	}

}

void start_quicksort_a(t_stack *stack)
{
	int pivote;
	t_node *href;
	int len;
	int i;

	len = ft_lenlst(stack->head_a);
	i = 0;
	if (check_inorder(stack))
		return ;
	if (len <= 3)
		start_sort_three(stack);
	else
	{
		href = stack->head_a;
		pivote = ft_pivote(stack->head_a);
		while (i < len && href)
		{
			//printf("Entro i = %d  NUm = %d\n", i, href->num);
			if (href->num <= pivote)
				ft_pb(stack);
			else if (href->num > pivote)
				ft_ra(stack);
			href = stack->head_a;
			i++;
		}
	start_quicksort_a(stack);
	}
}

void start_quicksort_b(t_stack *stack)
{
	int pivote;
	t_node *href;
	int len;
	int i;

	len = ft_lenlst(stack->head_b);

	href = stack->head_b;
	pivote = ft_pivote(stack->head_b);

	i = 0;
	if (len == 1)
		{
			ft_pa(stack);
			return ;
		}
	if (len <= 2)
	{
		//printf("AQUI YOY LEN = %d\n", len);
		//pri_stack_b(stack);
		if (stack->head_b->num < stack->head_b->next->num)
			{
				ft_sb(stack);
				ft_pa(stack);
				//ft_pa(stack);
			}
		else
		{
			ft_pa(stack);
			ft_pa(stack);
		}

	}
	else
		{
		while (i < len && href)
		{
			//printf("Estoy Aqui? i = %d\n", i);
			if (href->num >= pivote)
				ft_pa(stack);
			else if (href->num < pivote)
				ft_rb(stack);
			href = stack->head_b;
			i++;
		}
		start_quicksort_b(stack);
		}
}

void	startsort(t_stack *stack)
{
	if (stack->siza >= 2)
		start_sort_three(stack);
	if (stack->siza > 3){
		start_quicksort_a(stack);
		//pri_stack(stack);
		start_quicksort_b(stack);
	}

}
