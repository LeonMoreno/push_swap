#include "push_swap.h"

void ft_start(int argc, char **argv)
{
	t_stack stack;
	int i;
	
	stack.head_a = NULL;
	stack.head_b = NULL;
	stack.siza = 0;
	i = 1;
	while (argv[i])
		addnodefinal(&stack, ft_atoi(argv[i++]));
	pri_stack(&stack);
	//initsort(&stack);
	printf("argc = %d\n", argc);
	printf("siza = %d\n", stack.siza);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Mal No Argumentos\n");
	if (argc >= 2)
		ft_start(argc, argv);
	return (0);
}
