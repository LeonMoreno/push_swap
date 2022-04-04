#include "push_swap.h"

void	addnodefinal(t_stack *stack, int num)
{
	t_node	*node;
	t_node	*aux;

	node = createnode(num, stack);
	if (stack->head_a == NULL)
		stack->head_a = node;
	else
	{
		aux = stack->head_a;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}
}

t_node	*createnode(int num, t_stack *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new != NULL)
	{
		stack->siza += 1;
		new->num = num;
		new->next = NULL;
	}
	return (new);
}

void	pri_stack(t_stack *stack)
{
	t_node	*headref;

	printf("Stack A\n");
	headref = stack->head_a;
	while (headref)
	{
		printf ("%d\n", headref->num);
		headref = headref->next;
	}
}

void	pri_stack_b(t_stack *stack)
{
	t_node	*headref;

	printf("Stack B\n");
	headref = stack->head_b;
	while (headref != NULL)
	{
		printf ("%d\n", headref->num);
		headref = headref->next;
	}
}

t_node	*ft_before(t_node *node, t_stack *stack)
{
	t_node	*headref;

	headref = stack->head_a;
	while (headref && node->num != headref->next->num)
		headref = headref->next;
	return (headref);
}

int ft_lenlst(t_stack *stack)
{
	t_node *href;
	int i;

	i = 0;
	href = stack->head_a;
	while(href)
	{
		href = href->next;
		i++;
	}
	return (i);
}
