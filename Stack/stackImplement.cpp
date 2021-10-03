#include<iostream>

using namespace std;

#define MAX 5

class StackUsingArray{
	int tt=-1;
	int A[MAX];
public:
	// StackUsingArray(){
		// A[MAX];
	// }
	void push(int d){
		if(tt<MAX-1){
			A[++tt] = d;
		}else {
			cout<<"Stack is full!\n";
		}
	}
	bool isEmpty(){
		return tt == -1;
	}
	void pop(){
		if(!isEmpty()){
			--tt;
		}
	}
	int top(){
		if(!isEmpty()){
			return A[tt];
		}
	}
	
};

int main(){
	StackUsingArray s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	s.pop();
	cout<<s.top();
	return 0;
}