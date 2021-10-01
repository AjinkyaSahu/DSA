#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))
#define XOR(a, b) (struct node *)((uintptr_t)(a) ^ (uintptr_t)(b))

struct node{
	int data;
	struct node *xor_pn;
};

void push(struct node **head, struct node **tail, int value){
	struct node *temp, *curr;
	temp = allot;
	temp->data = value;
	temp->xor_pn = XOR(0, *head);
	
	if(*head==NULL){
		*head = temp;
		*tail = temp;
		return;
	}
	curr = *head;
	curr->xor_pn = XOR(temp, (*head)->xor_pn);
	*head = temp;
}

void pop(struct node **head, struct node **tail){
	struct node *curr, *last;
	curr = *head;
	
	if(curr->xor_pn==NULL){
		*head = NULL;
		*tail = NULL;
		return;
	}
	last = XOR((*tail)->xor_pn, 0);
	last->xor_pn = XOR(XOR(last->xor_pn, *tail), 0);
	*tail = last;
}

void show(struct node **head){
	struct node *prev, *curr, *next;
	prev = NULL;
	curr = *head;
	printf("\n\t");
	while(curr!=NULL){
		printf("%d ", curr->data);
		next = XOR(prev, curr->xor_pn);
		prev = curr;
		curr = next;
	}printf("\n");
}

int main(){
	int choice, value;
	struct node *head=NULL, *tail=NULL;
	
	while(true){
		printf("1. push\n2. pop\n3. show\n4. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to push: ");
				scanf("%d", &value);
				push(&head, &tail, value);
				break;
			case 2:
				if(head==NULL){
					printf("\n\t\tEmpty Queue!\n");
					break;
				}
				pop(&head, &tail);
				break;
			case 3:
				if(head==NULL){
					printf("\n\t\tEmpty Queue!\n");
					break;
				}
				show(&head);
				break;
			case 4:
				exit(0);
			default:
				printf("\n\t\tenter valid choice!\n");
		}
	}
	return 0;
}
