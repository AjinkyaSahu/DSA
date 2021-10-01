#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot (struct node *)malloc(sizeof(struct node))
int length=0;

struct node{
	int data;
	struct node *link;
};

void append(struct node **head, int value){
	struct node *ptr, *temp;
	temp = allot;
	
	temp->data = value;
	temp->link = NULL;

	if(*head==NULL){
		*head=temp;
		length++;
		return;
	}
	ptr = *head;
	while(ptr->link!=NULL){
		ptr = ptr->link;
	}
	ptr->link = temp;
	length++;
}

void prepend(struct node **head, int value){
	struct node *temp;
	temp = allot;
	
	temp->data = value;
	temp->link = *head;
	
	*head = temp;
	length++;
}

void insert(struct node **head, int pos, int value){
	int i;
	struct node *temp, *ptr;
	temp = allot;
	temp->data = value;

	ptr = *head;
	for(i=0; i<pos-1; i++){
		ptr = ptr->link;
	} temp->link = ptr;
	
	ptr = *head;
	for(i=0; i<pos-2; i++){
		ptr = ptr->link;
	} ptr->link = temp;
	
	length++;
}

void delete(struct node **head, int pos){
	int i;
	struct node *ptr, *next;
	ptr = *head;
	if(pos==1){
		*head = ptr->link;
		length--;
	}
	else if(pos==length){
		for(i=0; i<pos-2; i++){
			ptr = ptr->link;
		}
		ptr->link = NULL;
		length--;
	}
	else{
		ptr = *head;
		for(i=0; i<pos-2; i++){
			ptr = ptr->link;
		}
		next = ptr->link->link;
		ptr->link = next;
		length--;
	}
}

void show(struct node *head){
	struct node *ptr;
	ptr=head;
	printf("\t");
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\tlength: %d\n", length);
}

int main(){
	int choice, value, pos;
	struct node *head = NULL;
	
	while(true){
		printf("1. append\n2. prepend\n3. insert\n4. delete\n5. show\n6. exit\nenter: ")	;
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
				if(pos<=1 || pos>length){
					if(pos==1)
						printf("\n\t\tto insert at position 1 use prepend option\n");

					else
						printf("\n\t\tlist index out of range!\n");
					break;
				}
				insert(&head, pos, value);
				break;
			case 4:
				if(head==NULL){
					printf("\n\t\tEmpty list!\n");
					break;
				}
				printf("\n\tenter position of number to delete: ");
				scanf("%d", &pos);
				if(pos<1 || pos>length){
					printf("\n\t\tlist index out of range!\n");
					break;
				}
				delete(&head, pos);
				break;
			case 5:
				if(head==NULL){
					printf("\n\t\tEmpty list!\n");
					break;
				}
				show(head);
				break;
			case 6:
				exit(0);
			default:
				printf("\n\t\tenter valid choice!\n");
		}
	}
	return 0;
}
