#include <stdio.h>
/*pRimero creo la estructura, la cual va a contener los nodos
 * de cada uno de lista enlazada
 * MUY IMPORTANTE: el elemento *next debe ser "struct name struct"
 */
typedef struct s_list
{
	int i;
	struct s_list *next;
} t_list;

void ft_printlst(t_list *head)
{
	t_list *headRef;

	headRef = head;
	while(headRef != NULL)
	{
		printf("Valor en ft_ens %d\n", headRef->i);
		headRef = headRef->next;
	}
}

/* Cada nodo lo creo con el tipo q llame la struct redefinido por typedef
 * y Lo mas IMPORTANTE, un puntero tipo del mismo tipo de mi nodo
 * este puntero apunta a mi primer nodo
 * el *next de cada nodo apunta al siguiente la direccion del siguiente
 * nodo. */
int main(void)
{
	t_list nodo1;
	t_list nodo2;
	t_list nodo3;

	t_list *head;

	head = &nodo1;
	nodo1.next = &nodo2;
	nodo2.next = &nodo3;
	nodo3.next = 0;

	nodo1.i = 42;
	nodo2.i = 107;
	nodo3.i = 7;
	
	ft_printlst(head);
	return (0);
}


