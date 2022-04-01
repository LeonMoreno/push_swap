#include <stdio.h>
#include <stdlib.h>

typedef struct node_a
{
  int num;
  struct node_a *next;
} node_a;

typedef struct node_b
{
  int num;
  struct node_b *next;
} node_b;

void creat_node(node_a **head_a, int num)
{
  node_a *node;
  node_a *tmp;
  
  node = malloc(sizeof(node_a));
  if (*head_a == NULL)
    {
      node->num = num * 3;
      node->next = NULL;
      *head_a = node;
    }
  else
    {
      node->num = num * 2;
      node->next = NULL;
      tmp = *head_a;
      while (tmp->next != NULL)
      {
        tmp = tmp->next;
      }
      tmp->next = node;
    }
}

void ft_pb(node_a **head_a, node_b **head_b)
{
  node_a *tmp;
  node_b *tmp_b;
  
  tmp = *head_a;
  *head_a = tmp->next;
  tmp->next = NULL;
  tmp_b = *head_b;
  *head_b = *((head_a *) &tmp); // No se puede hacer casting en structs/
	/* y Tampoco se puede copia de una struct a otra asi sean identicas*/
}
  
      
int main() {
  node_a *head_a = NULL;
  node_b *head_b = NULL;
  int i = 0;

  while (i < 4)
  {
    creat_node(&head_a, i);
    i++;
  }
  ft_pb(&head_a, &head_b);
  
  return 0;
}
