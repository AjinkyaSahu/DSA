#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))
#define XOR(a, b) (struct node *) ((uintptr_t)(a) ^ (uintptr_t)(b))
int length=0;

struct node{
	int data;
	struct node *xor_pn;
};

//struct node* XOR (struct node *a, struct node *b){
//    return (struct node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
//}

void append(struct node **head, struct node **tail, int value){
    // Allocate memory for new node
    struct node *temp = allot;
    temp->data = value;
 
    /* Since new node is being inserted at the
       end, xor_pn of new node will always be
       XOR of current tail and NULL */
    temp->xor_pn = XOR(*tail, 0);
    
    if(*head==NULL){
    	*head = temp;
    	*tail = temp;
    	length++;
    	return;
	}
 
    /* If linked list is not empty, then xor_pn of
       current tail node will be XOR of node previous to
	   current tail and new node */
    if (*tail != NULL){
        // *(tail)->xor_pn is XOR of previous and NULL.
        // So if we do XOR of it with NULL, we get previous
        (*tail)->xor_pn = XOR((*tail)->xor_pn, temp);
    }
 
    // Change tail
    *tail = temp;
    length++;
}

void prepend(struct node **head, struct node **tail, int value){
    // Allocate memory for new node
    struct node *temp = allot;
    temp->data = value;
 
    /* Since new node is being inserted at the
       beginning, xor_pn of new node will always be
       XOR of current head and NULL */
    temp->xor_pn = XOR(0, *head);
    
    if(*head==NULL){
    	*head = temp;
    	*tail = temp;
    	length++;
    	return;
	}
 
    /* If linked list is not empty, then xor_pn of
       current head node will be XOR of new node
       and node next to current head */
    if (*head != NULL){
        // *(head)->xor_pn is XOR of NULL and next.
        // So if we do XOR of it with NULL, we get next
        (*head)->xor_pn = XOR(temp, (*head)->xor_pn);
    }
 
    // Change head
    *head = temp;
    length++;
}
 
void insert(struct node **head, int pos, int value){
	int i;
	struct node *temp, *prev, *prev2, *curr, *next;
	prev = NULL;
	curr = *head;
	temp = allot;
	temp->data = value;
	
	for(i=0; i<pos-1; i++){
		next = XOR(prev, curr->xor_pn);
		prev = curr;
		curr = next;
	}
	temp->xor_pn = XOR(prev, curr);
	prev2 = prev;
	prev->xor_pn = XOR(XOR(prev->xor_pn, curr), temp);
	curr->xor_pn = XOR(temp, XOR(prev2, curr->xor_pn));
	length++;
}

void delete(struct node **head, struct node **tail, int pos){
	int i;
	struct node *prev, *curr, *next;
	prev = NULL;
	curr = *head;
	
	if(curr->xor_pn==0){
		*head=NULL;
		*tail=NULL;
		length--;
		return;
	}
	
	if(pos==1){
		*head = XOR(0, curr->xor_pn);
		(*head)->xor_pn = XOR(0, XOR(curr, (*head)->xor_pn));
		
		length--;
		return;
	}
	
	if(pos==length){
		for(i=0; i<pos-1; i++){
			next = XOR(prev, curr->xor_pn);
			prev = curr;
			curr = next;			
		}
		prev->xor_pn = XOR(XOR(prev->xor_pn, curr), 0);
		*tail = prev;
		length--;
		return;
	}
	
	for(i=0; i<pos-1; i++){
		next = XOR(prev, curr->xor_pn);
		prev = curr;
		curr = next;
	}
	prev->xor_pn = XOR(XOR(prev->xor_pn, curr), XOR(prev, curr->xor_pn));
	next = XOR(prev, curr->xor_pn);
	next->xor_pn = XOR(prev, XOR(curr, next->xor_pn));
	length--;
}

void show(struct node **head){
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *next;
 
 	printf ("\n\t");
    while(curr != NULL){
        printf ("%d ", curr->data);

        next = XOR (prev, curr->xor_pn);

        prev = curr;
        curr = next;
    }printf("\tlength: %d\n", length);
}
 

int main(){
	int choice, value, pos;
	struct node *head=NULL, *tail=NULL;
	
	while(true){
		printf("1. append\n2. prepend\n3. insert\n4. delete\n5. show\n6. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to append: ");
				scanf("%d", &value);
				append(&head, &tail, value);
				break;
			case 2:
				printf("\n\tenter value to prepend: ");
				scanf("%d", &value);
				prepend(&head, &tail, value);
				break;
			case 3:
				if(head==NULL){
					printf("\n\t\tEmpty List!\n");
					break;
				}
				printf("\n\tenter position and value to insert: ");
				scanf("%d %d", &pos, &value);
				if(pos<=1 || pos>length){
					if(pos==1)
						printf("\n\t\tto insert at position 1 use prepend option!\n");
					else
						printf("\n\t\tlist index out of range!\n");
					break;
				}
				insert(&head, pos, value);
				break;
			case 4:
				if(head==NULL){
					printf("\n\t\tEmpty List!\n");
					break;
				}
				printf("\n\tenter position of element to delete: ");
				scanf("%d", &pos);
				if(pos<1 || pos>length){
					printf("\n\t\tlist index out of range!\n");
					break;
				}
				delete(&head, &tail, pos);
				break;
			case 5:
				if(head==NULL){
					printf("\n\t\tEmpty List!\n");
					break;
				}
				show(&head);
				break;
			case 6:
				exit(0);
			default:
				printf("\n\t\tenter valid choice!\n")	;
		}
	}
	return 0;
}
