#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))
#define XOR(a, b) (struct node *) ((uintptr_t)(a) ^ (uintptr_t)(b))

struct node{
	int data;
	struct node *xor_pn;
};

void push(struct node **head, int value){
	struct node *temp;
	temp = allot;
	temp->data = value;
	temp->xor_pn = XOR(0, *head);
	
	if(*head==NULL){
		*head = temp;
		return;
	}
	(*head)->xor_pn = XOR(temp, (*head)->xor_pn);
	*head = temp;
}

void pop(struct node **head){
	struct node *curr;
	curr = *head;
	if(curr->xor_pn==0){
		*head=NULL;
		return;
	}
	*head = XOR(0, curr->xor_pn);
	(*head)->xor_pn = XOR(0, XOR(curr, (*head)->xor_pn));
}

void show(struct node **head){
	struct node *prev, *curr, *next;
	prev=NULL;
	curr=*head;
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
	struct node *head=NULL;
	
	while(true){
		printf("1. push\n2. pop\n3. show\n4. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to push: ");
				scanf("%d", &value);
				push(&head, value);
				break;
			case 2:
				if(head==NULL){
					printf("\n\t\tEmpty Stack!\n");
					break;
				}
				pop(&head);
				break;
			case 3:
				if(head==NULL){
					printf("\n\t\tEmpty Stack!\n");
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
