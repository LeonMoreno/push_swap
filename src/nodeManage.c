#include "push_swap.h"

void addnodefinal(t_stack *stack, int num)
{
	a_node *node;
	a_node *aux;
	
	node = createnode(num);	
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

a_node *createnode(int num)
{
	a_node *new;

	new = malloc(sizeof(a_node));
	if (new != NULL)
	{
		new->num = num;
		new->next = NULL;
	}
	return (new);
}

void pri_stack(t_stack *stack)
{
	a_node *headRef;
	
	printf("Stack A\n");
	headRef = stack->head_a;
	while (headRef)
	{
		printf ("%d\n", headRef->num);
		headRef = headRef->next;
	}
}
