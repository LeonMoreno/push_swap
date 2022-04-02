#include "push_swap.h"

void ft_start(char **argv)
{
	t_stack stack;
	int i;
	
	stack.head_a = NULL;
	stack.head_b = NULL;
	stack.siza = 0;
	i = 1;
	while (argv[i])
		addnodefinal(&stack, ft_atoi(argv[i++]));
	startsort(&stack);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Mal No Argumentos\n");
	if (argc >= 2)
		ft_start(argv);
	return (0);
}
