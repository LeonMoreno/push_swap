=#include <stdio.h>
#include <stdlib.h>

typedef struct s_frame
{
	int num;
	struct s_frame *next;
} t_frame;

typedef struct s_stack{
	t_frame *head;
	t_frame *last;
	int		size;
} t_stack;

void ft_addlast(int num, t_stack *stack)
{
	t_frame *nodo;

	nodo = malloc(sizeof(t_frame));
	if (stack->head == NULL)
	{
		nodo->num = num;
		nodo->next = NULL;
		stack->head = nodo;
		stack->size = 1;
	}
	else
	{
		nodo->num = num;
		nodo->next = stack->head;
		stack->head = nodo;
		stack->size += 1;
	}
}

void print_list(t_stack *stack)
{
	t_frame *ptr;

	ptr = stack->head;
	while (ptr)
	{
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
}

void get_last(t_stack *stack)
{
	t_frame *headRef;

	headRef = stack->head;
	while (headRef)
	{
		stack->last = headRef;
		headRef = headRef->next;

	}
}

t_frame *ft_before(t_frame *ptr, t_stack *stack)
{

	t_frame *headTemp;
	t_frame *before;

	headTemp = stack->head;
	while (headTemp && headTemp->num != ptr->num)
	{
		before = headTemp;
		headTemp = headTemp->next;
	}
	return (before);
}

t_frame *ft_switch(t_frame *headref, t_frame *minref, t_stack *stack)
{
	t_frame *tmp;
	t_frame *before_1;
	t_frame *before_2;


	if (headref == minref)
		return (minref);
	else if (minref == stack->head)
	{
		printf("EN IF Estoy headRef-num = %d\n", headref->num);
		printf("EN IF Estoy MinRef-num = %d\n", minref->num);

		before_1 = ft_before(headref, stack);
		before_1->next = headref->next;
		stack->head = headref;
		headref->next = minref;
		//tmp = minref->next;
		//minref->next = headref->next;


	//	print_list(stack);
	}
	else
	{
	//	printf("En ELSE Estoy headRef-num = %d\n", headref->num);
	//	printf("EN ELSE Estoy MinRef-num = %d\n", minref->num);

		tmp = minref->next;
		before_1 = ft_before(headref, stack);
		before_2 = ft_before(minref, stack);
		minref->next = headref->next;
		headref->next = tmp;
		before_2->next = headref;
		before_1->next = minref;
		minref = tmp;
	}
	return (minref);
}

void partir(t_stack *stack)
{
	int pivote;
	t_frame *headref;
	t_frame *minref;

	pivote = stack->last->num;
	headref = stack->head;
	minref = stack->head;

	//printf("PIvote = %d\n", pivote);
	while (headref->next)
	{
		if (headref->num < pivote)
			minref = ft_switch(headref, minref, stack);
		headref = headref->next;
	}
	ft_switch(headref, minref, stack);
}

void quickSort(t_stack *stack)
{
	t_frame *headRef;

	headRef = stack->head;
	if (headRef->next != NULL)
	{
		partir(stack);
	}
}

int main(int argc, char **argv)
{
	t_stack stack;
	int i;

	stack.head = NULL;
	i = 1;
	while (i < argc)
	{
		ft_addlast(atoi(argv[i]), &stack);
		i++;
	}
	print_list(&stack);
	get_last(&stack);
	printf("Last = %d\n", stack.last->num);
	quickSort(&stack);
	print_list(&stack);

}
