#include<bits/stdc++.h>
using namespace std;
#define size 100
class Stack{
	public:
	int t = -1;
	int arr[size] = {-1};
	int top(){
		return arr[t];
	}
	void push(int data){
		if(t<size-1){
			arr[++t] = data;
		}else{
			cout<<"Stack is full!\n";
		}
	}
	int pop(){
		if(t!=-1){
			int x = arr[t];
			arr[t--] = -1;
			return x;
		}else{
			cout<<"Stack is empty!\n";
			return 0;
		}
	}
	bool empty(){
		if(t==-1){
			return true;
		}
		return false;
	}
};
class Queue{
	public:
	Stack stack1, stack2;
	
	void enqueue(int data){
		stack1.push(data);
	}
	void dequeue(){
		if(stack1.empty() && stack2.empty()){
			cout<<"Queue is empty!\n";
			return;
		}
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack2.pop();
	}
	void display(){
		if(stack1.empty() && stack2.empty()){
			cout<<"Queue is empty!\n";
			return;
		}
		Stack auxStack1, auxStack2;
		if(stack2.empty()){
			auxStack2 = stack1;
			while(!auxStack2.empty()){
				auxStack1.push(auxStack2.top());
				auxStack2.pop();
			}
			while(!auxStack1.empty()){
				cout<<auxStack1.pop()<<" ";
			}
			cout<<"\n";
			return;
		}else{
			auxStack1 = stack2;
			while(!auxStack1.empty()){
				cout<<auxStack1.pop()<<" ";
			}
			auxStack2 = stack1;
			while(!auxStack2.empty()){
				auxStack1.push(stack1.top());
				auxStack2.pop();
			}
			while(!auxStack1.empty()){
				cout<<auxStack1.pop()<<" ";
			}
			cout<<"\n";
			return;
		}
	}
	
};

int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(100);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();



	return 0;
}