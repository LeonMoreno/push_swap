#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/include/libft.h"

/*struct stack a*/
typedef struct s_fra
{
	int num;
	struct s_fra *next;
} t_fra;

/*Struct stack b */
typedef struct s_frb
{
	int num;
	struct s_frb *next;
} t_frb;

/*Info cabecera de cada stack */
typedef struct s_stack
{
	t_fra 	*head_a;
	t_frb	*head_b;
	int				siza;
} t_stack;

void ft_interadd(char **argv);


#endif





