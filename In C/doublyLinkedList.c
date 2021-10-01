#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))
int length=0;

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void append(struct node **head, int value){
	struct node *temp, *ptr;
	temp = allot;
	
	temp->prev = NULL;
	temp->data = value;
	temp->next = NULL;
	
	if(*head==NULL){
		*head = temp;
		length++;
		return;
	}
	
	ptr = *head;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	temp->prev = ptr;	
	length++;
}

void prepend(struct node **head, int value){
	struct node *temp, *ptr;
	ptr = *head;
	temp = allot;
	
	temp->prev = NULL;
	temp->data = value;
	temp->next = NULL;
	
	if(*head==NULL){
		*head = temp;
		length++;
		return;
	}
	
	temp->next = ptr;
	ptr->prev = temp;
	*head = temp;
	length++;
}

void insert(struct node **head, int pos, int value){
	int i;
	struct node *temp, *ptr;
	temp = allot;
	temp->data = value;
	
	ptr = *head;
	for(i=0; i<pos-2; i++){
		ptr = ptr->next;
	}
	temp->next = ptr->next;				//next of temp to pos
	ptr->next->prev = temp;				//prev of pos to temp
	temp->prev = ptr;					//prev of temp to pos-1(ptr)
	ptr->next = temp;					//next of pos-1(ptr) to temp
	length++;
}

void delete(struct node **head, int pos){
	int i;
	struct node *ptr;
	ptr = *head;
	if(pos==1){
		*head = ptr->next;
		length--;
		return;
	}
	else if(pos==length){
		while(ptr->next->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = NULL;
		length--;
		return;
	}
	
	for(i=0; i<pos-2; i++){
		ptr = ptr->next;
	}
	ptr->next = ptr->next->next;
	length--;	
}

void show(struct node **head){
	struct node *ptr;
	ptr = *head;
	printf("\n\t");
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}printf("\tlength: %d\n", length);
}

int main(){
	int choice, value, pos;
	struct node *head=NULL;
	
	while(true){
		printf("1. append\n2. prepend\n3. insert\n4. delete\n5. show\n6. exit\nenter: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter value to append: ");
				scanf("%d", &value);
				append(&head, value);
				break;
			case 2:
				printf("\n\tenter value to prepend: ");
				scanf("%d", &value);
				prepend(&head, value);
				break;
			case 3:
				if(head==NULL){
					printf("\n\t\tEmpty list!\n");
					break;
				}
				printf("\n\tenter position and value to insert: ");
				scanf("%d %d", &pos, &value);
				if(pos<1 || pos>length){
					if(pos==1)
						printf("\n\t\tto insert at position 1 use prepend option!\n");
					else
						printf("\n\t\tlist out of range!\n");
					break;
				}
				insert(&head, pos, value);
				break; 
			case 4:
				if(head==NULL){
					printf("\n\t\tEmpty list!\n");
					break;
				}
				printf("\n\tenter position to delete: ");
				scanf("%d", &pos);
				if(pos<1 || pos>length){
					printf("\n\t\tlist out of range!\n");
					break;
				}
				delete(&head, pos);
				break;
			case 5:
				if(head==NULL){
					printf("\n\t\tEmpty list!\n");
					break;
				}
				show(&head);
				break;
			case 6:
				exit(0);
			default:
				printf("\n\t\tenter valid choice!\n");
		}
	}
	return 0;
}
