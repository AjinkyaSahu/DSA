#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot(size) (int *)malloc(size * sizeof(int))
void push(int, int *);
void pop(int *);
void display(int *);
int size, length=0;
int main(){
	int *queue, choice, number;
	char stop='n';
	printf("Enter size of queue : ");
	scanf("%d", &size);
	queue = allot(size);
	while(stop!='y'){
		printf("1. push\n2. pop\n3. show\n");
		printf("choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter number to push: ");
				scanf("%d", &number);
				push(number, queue);
				break;
			case 2:
				pop(queue);
				break;
			case 3:
				display(queue);
				break;
			default:
				printf("\nenter valid choice\n");
		}fflush(stdin);
		
		printf("=> stop execution(y/n): ");
		scanf("%c", &stop);
	}
}

bool isEmpty(){
	if(length<=0)
		return true;
	return false;
}

bool isFull(){
	if(length>=size)
		return true;
	return false;
}

void push(int number, int queue[]){
	if(isFull()){
		printf("Queue Overflow!\n");
		return;
	}
	queue[length]=number;
	length++;
}

void pop(int queue[]){
	int i;
	if(isEmpty()){
		printf("Empty Queue!\n");
		return;
	}
	for(i=0; i<length-1; i++){
		queue[i]=queue[i+1];
	}
	length--;
}

void display(int queue[]){
	int i;
	if(isEmpty()){
		printf("Empty Queue!\n");
		return;
	}
	for(i=length-1; i>=0; i--){
		printf("%d\n", queue[i]);
	}
}
