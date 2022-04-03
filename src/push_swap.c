#include "push_swap.h"

int parser_argv(char **argv)
{
    int i;
    int spa;

    i = 0;
    spa = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

t_stack start_stack(char **argv)
{
	t_stack stack;
	char **res_split;
	int res_spa;
	int	i;

	stack.siza = 0;
	res_spa = parser_argv(argv);
	if (res_spa == 0)
	{
		i = 1;
		while (argv[i])
			addnodefinal(&stack, ft_atoi(argv[i++]));
	}
	else
	{
		i = 0;
		res_split = ft_split(argv[1], ' ');
		while (res_split[i])
			addnodefinal(&stack, ft_atoi(res_split[i++]));
	}
	return (stack);
}

void ft_start(char **argv)
{
	t_stack stack;
	
	stack.head_a = NULL;
	stack.head_b = NULL;
	stack = start_stack(argv);
	start_checker(&stack);
	if (stack.inorder == 1)
		exit (0);	
	pri_stack(&stack);
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
