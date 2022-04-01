#include "push_swap.h"

void ft_start(int argc, char **argv)
{
	t_stack stack;
	int i;
	
	stack.head_a = NULL;
	i = 1;
	while (argv[i])
	{
		addnodefinal(&stack, ft_atoi(argv[i]));
		i++;
	}
	pri_stack(&stack);

	if (stack.head_a->num > stack.head_a->next->num)
		ft_sa(&stack);

	pri_stack(&stack);
	printf("argc = %d\n", argc);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Mal No Argumentos\n");
	if (argc >= 2)
		ft_start(argc, argv);
	return (0);
}
