#include "push_swap.h"

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

void start_quicksort_3(t_stack *stack, int len)
{
	int	p;
	int	s;
	int	t;

	if (len == 2)
	{
		if (stack->head_a->num > stack->head_a->next->num)
			ft_sa(stack);
	}
	else if (len == 3 && stack->siza == 3)
		start_sort_three(stack);
	else if (len == 3)
		{
			p = stack->head_a->num;
			s = stack->head_a->next->num;
			t = stack->head_a->next->next->num;
			if (p < s && s > t && t > p)
			{
				ft_pb(stack);
				ft_sa(stack);
				ft_pa(stack);
			}
			else if (p > s && s > t && t < p)
			{
				ft_sa(stack);
				ft_pb(stack);
				ft_sa(stack);
				ft_pb(stack);
				ft_sb(stack);
				ft_pa(stack);
				ft_pa(stack);
			}
			else if (p < s && s > t && t < p)
			{
				ft_pb(stack);
				ft_sa(stack);
				ft_pb(stack);
				ft_sb(stack);
				ft_pa(stack);
				ft_pa(stack);
			}
			else if (p > s && s < t && t > p)
				ft_sa(stack);
			else if (p > s && s < t && t < p)
			{
				ft_sa(stack);
				ft_pb(stack);
				ft_sa(stack);
				ft_pa(stack);
			}
		}
	//	printf("p = % d, s = %d, t = %d\n", p, s, t);
}

void start_quicksort_3_b(t_stack *stack, int len)
{
	int p;
	int s;
	int t;

	if (len == 1)
		ft_pa(stack);
	else if (len == 2)
		{
			p = stack->head_b->num;
			s = stack->head_b->next->num;
			//printf("quicSOrt3B sizb = %d \n", stack->sizb);
			if (p < s)
				ft_sb(stack);
			ft_pa(stack);
			ft_pa(stack);
		}
	else if (len == 3 && stack->sizb == 3)
		{

			p = stack->head_b->num;
			s = stack->head_b->next->num;
			t = stack->head_b->next->next->num;
			//printf("quicSOrt_3B sizb = %d p = %d s %d t %d \n", stack->sizb, p , s, t);
			if (p < s && s > t && t > p)
				ft_rb(stack);
			else if ( p < s && s < t && t > p)
			{
				ft_rb(stack);
				ft_sb(stack);
			}
			else if (p > s && s < t && t < p)
			{
				ft_rrb(stack);
				ft_sb(stack);
			}
			else if (p > s && s < t && t > p)
			{
				//printf("Aqui TOY \n");
				ft_rrb(stack);
				//pri_stack_b(stack);
			}
			else if (p < s && s > t && t < p)
				ft_sb(stack);
			ft_pa(stack);
			ft_pa(stack);
			ft_pa(stack);
		}
	else if (len == 3)
		{

			p = stack->head_b->num;
			s = stack->head_b->next->num;
			t = stack->head_b->next->next->num;
		//	printf("quicSOrt_3B sizb = %d p = %d s %d t %d \n", stack->sizb, p , s, t);
			if (p < s && s > t && t > p)
				{
					ft_sb(stack);
					ft_pa(stack);
					ft_sb(stack);
					ft_pa(stack);
					ft_pa(stack);
				}
			else if ( p < s && s < t && t > p)
			{
				ft_rb(stack);
				ft_sb(stack);
				ft_pa(stack);
				ft_pa(stack);
				ft_rrb(stack);
				ft_pa(stack);
			}
			else if (p > s && s < t && t < p)
			{
				ft_pa(stack);
				ft_sb(stack);
				ft_pa(stack);
				ft_pa(stack);
			}
			else if (p > s && s < t && t > p)
			{
				ft_rb(stack);
				ft_sb(stack);
				ft_pa(stack);
				ft_rrb(stack);
				ft_pa(stack);
				ft_pa(stack);
			}
			else if (p < s && s > t && t < p)
				{
					ft_sb(stack);
					ft_pa(stack);
					ft_pa(stack);
					ft_pa(stack);
				}
			else if (p > s && s > t && t < p)
			{
				ft_pa(stack);
				ft_pa(stack);
				ft_pa(stack);
			}
		}
}

void ft_bublesort(int *arr, int len)
{
	int i;
	int j;
	int tmp;

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

int ft_getpivote(t_node *n, int len)
{
	int *arr;
	t_node *s;
	int i;
	int pivote;

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
	return (pivote);
}

 void start_quicksort_a(t_stack *stack, int len)
 {
	t_node *s;
	int pivote;
	int nodes;
	int chu;

//	 printf("len = %d // siza = %d \n", len, stack->siza);
	if (check_inorder(stack, len) == 1)
	{
	//	printf("ORDENADO SE VA POR AQUI\n");
		return ;
	}

	if (len <= 3)
		{
			//pri_stack(stack);
			//printf("MENOR q 3\n");
			start_quicksort_3(stack, len);
		//	pri_stack(stack);
			return ;
		}
	s = stack->head_a;
	nodes = len;
	chu = 0;
	pivote = ft_getpivote(stack->head_a, len);
	//printf ("pivote = %d\n", pivote);

	 while (s && len != (nodes / 2 + nodes % 2))
	 {
		 if (s->num < pivote)
		 	{
				 ft_pb(stack);
				 len--;
			 }
		 else
		 	{
				ft_ra(stack);
				chu++;
		 	}
		s = stack->head_a;
	 }
	 while ((nodes / 2 + nodes % 2) != stack->siza && chu)
		{
			ft_rra(stack);
			chu--;
		}
		//printf ("SIZA = %d\n", stack->siza);
		//printf ("SIZ_B = %d\n", stack->sizb);
	 start_quicksort_a(stack, nodes / 2 + nodes % 2);
	 start_quicksort_b(stack, nodes / 2);
 }

void start_quicksort_b(t_stack *stack, int len)
{
	t_node *s;
	int pivote;
	int nodes;
	int chu;

//	printf("LEN B = %d y SIZB = %d\n", len, stack->sizb);
//	pri_stack_b(stack);
	if (ft_check_inverse_order(stack, len))
	{
		while (len)
			{
				ft_pa(stack);
				len--;
			}
		return ;
	}

	if (len <= 3)
		{
		//	printf("SORT_B SE VA POR AQUI MENOr 3\n");
			start_quicksort_3_b(stack, len);
			return ;
		}
	s = stack->head_b;
	nodes = len;
	chu = 0;
	pivote = ft_getpivote(stack->head_b, len);
	//printf("pivote B = %d Y LEN = %d\n", pivote, len);
	while (s && len != (nodes / 2))
	 {
		 if (s->num >= pivote)
		 	{
				 ft_pa(stack);
				 len--;
			 }
		 else
		 	{
				ft_rb(stack);
				chu++;
		 	}
		s = stack->head_b;
	 }
	 while (nodes / 2 + nodes % 2 != stack->sizb && chu)
	 {
		 ft_rrb(stack);
		 chu--;
	 }
	 start_quicksort_a(stack, nodes / 2 + nodes % 2);
	 start_quicksort_b(stack, nodes / 2);
}

void	startsort(t_stack *stack)
{
		if (stack->siza == 2)
			ft_sa(stack);
		else if (stack->siza == 3)
			start_sort_three(stack);
		else
		start_quicksort_a(stack, stack->siza);
}
