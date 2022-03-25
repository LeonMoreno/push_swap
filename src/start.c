#include "push_swap.h"



void nodoadd(int num, t_stack *stack)
{
	t_fra *nodo;

	nodo = malloc(sizeof(t_fra));

	if (stack->head_a == NULL)
	{
		nodo->num = num;
		nodo->next = NULL;
		stack->head_a = nodo;
		stack->siza = 1;
	}
else
	{
		nodo->num = num;
		nodo->next = stack->head_a;
		stack->head_a = nodo;
		stack->siza += 1;
	}
}

void ft_interadd(char **argv)
{
	t_stack stack;
	int i;

	stack.head_a = NULL;
	i = 1;
	while (argv[i])
	{
		nodoadd(ft_atoi(argv[i]), &stack);
		i++;
	}
	//printf("Num es %d\n", fra.num);
}
