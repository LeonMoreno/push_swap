#include <stdio.h>
#include <stdlib.h>

typedef struct node_a
{
  int num;
  struct t_node *next;
} t_node;

typedef struct s_stack{
    t_node *head_a;
    t_node *head_b;
    int        siza;
} t_stack;

t_node    *createnode(int num, t_stack *stack)
{
    t_node    *new;

    new = malloc(sizeof(t_node));
    if (new != NULL)
    {
        stack->siza += 1;
        new->num = num;
        new->next = NULL;
    }
    return (new);
}

void    addnodefinal(t_stack *stack, int num)
{
    t_node    *node;
    t_node    *aux;

    node = createnode(num, stack);
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

/*
void    ft_pb(t_stack *stack)
{
    t_node    *tmp_a;

    tmp_a = stack->head_a;
    stack->head_a = stack->head_a->next;
    if (stack->head_b == NULL)
    {
        tmp_a->next = NULL;
        stack->head_b = tmp_a;
    }
    else
    {
        tmp_a->next = stack->head_b;
        stack->head_b = tmp_a;
    }
    printf("pb\n");
}*/


int main() {

    t_stack stack;
    
    stack.siza = 0;
    stack.head_a = NULL;
    stack.head_b = NULL;
  int i = 0;

  while (i < 4)
  {
      addnodefinal(&stack, i);
    i++;
  }
  //ft_pb(&head_a, &head_b);
  
  return 0;
}

