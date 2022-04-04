#include "push_swap.h"

void msg_err(char *msg_err)
{
	write(2, msg_err, ft_strlen(msg_err));
	exit(1);
}

int ft_pivote(t_stack *stack)
{
	int num;
	t_node *href;

	href = stack->head_a;
	while (href->next)
		href = href->next;
	num = href->num;


	return(num);
}
