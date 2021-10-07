#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if (n==NULL)
    {
        return 1;
    }
    
    n->number = 1;
    n->next = NULL;
    list = n;
    
     n = malloc(sizeof(node));
     if (n == NULL)
     {
         free(list);
         return 1;
     }
     n->number = 2;
     n->next=NULL;
     list->next = n;
     
     n = malloc(sizeof(node));
     if(n==NULL)
     {
         free(list->next);
         free(list);
         return 1;
     }
     n->number = 3;
     n->next=NULL;
     list->next->next = n;
     
     for (node *temp = list; temp!=NULL; temp->next)
     {
         printf("%i\n", temp->number);
     }
     
     while (list!=NULL)
     {
         node *temp = list->next;
         free(list);
     }
}
