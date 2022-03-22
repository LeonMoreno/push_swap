#include <stdio.h>
#include <stdlib.h>

typedef struct s_frame
{
    int num;
    struct s_frame *next;
} t_frame;

typedef struct s_stack{
    t_frame *head;
    t_frame *last;
    int        size;
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

/*void quickSort(t_stack *stack)
{
    t_frame *headRef;

    headRef = stack->head;
    if (headRef->next != NULL)
    {
        partir = (stack);
    }
}*/

void ft_switch(t_stack *stack)
{
  t_frame *headRef;
  t_frame *minRef;
  t_frame *tmp;

  headRef = stack->head->next->next;
  minRef = stack->head;

  tmp = headRef->next;
  headRef->next = minRef->next;
  minRef->next = minRef->next->next;
  headRef->next->next = tmp;



}

int main(void)
{
    t_stack stack;
    int i;
    int arr[] = {8, 11, 5, 6, 9};

    stack.head = NULL;
    i = 0;
    while (i < 5)
    {
        ft_addlast(arr[i], &stack);
        i++;
    }
 //   print_list(&stack);
   // get_last(&stack);
  //  quickSort(&stack);
  ft_switch(&stack);
}
