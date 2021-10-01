#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allot(size) (int *)malloc(size * sizeof(int))
void push(int, int *);
void pop(int *);
void display(int *);
int size, length=0;

int main(){
	int *stack, choice, number;
	char stop='n';
	printf("Enter the size of stack you want : ");
	scanf("%d", &size);
	stack = allot(size);
	while(stop != 'y'){
		printf("1. push\n2. pop\n3. show\n");
		printf("choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("\n\tenter number to push: ");
				scanf("%d", &number);
				push(number, stack);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				display(stack);
				break;
			default:
				printf("\nenter valid choice\n");
		}fflush(stdin);
			
		printf("=> Stop execution(y/n) : ");
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

void push(int number, int stack[]){
	if(isFull()){
		printf("Stack Overflow!\n");
		return;
	}	
	stack[length]=number;
	length++;
	printf("length: %d, size: %d\n", length, size);
}

void pop(int stack[]){
	if(isEmpty()){
		printf("Empty Stack!\n");
		return;
	}
	stack[length-1]=-1;
	length--;
}

void display(int stack[]){
	int i;
	if(isEmpty()){
		printf("Empty Stack!\n");
	}
	for(i=length-1; i>=0; i--){
		if(stack[i]!=-1){
			printf("%d\n", stack[i]);
		}
	}
}
