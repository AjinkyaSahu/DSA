#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class List{
	Node* head;
public:
	List(){
		head = NULL;
	}
	void insert(int d){
		Node* node = new Node();
		node->data = d;
		node->next = NULL;
		if(head==NULL){
			head = node;
		} else{
			Node* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = node;
		}
	}
	void insert(int d, int pos){
		Node* node = new Node();
		node->data = d;
		node->next = NULL;
		if(pos==1){
			node->next = head;
			head = node;
			return;
		}
		Node* temp = head;
		int i;
		for(i=0; i<pos-2; ++i){
			temp = temp->next;
			if((temp->next==NULL) && (i<=pos-4)){
				cout<<"Invalid pos!\n";
				return;
			}
		}
		node->next = temp->next;
		temp->next = node;
	}
	void deleteNode(int pos){
		Node* node = head;
		if(pos==1){
			head = node->next;
			delete(node);
			return;
		}
		for(int i=0; i<pos-2; ++i){
			node = node->next;
			if((node->next == NULL) && (i<=pos-3)){
				cout<<"Invalid index!\n";
				return;
			}
		}
		Node* t = node->next;
		node->next = t->next;
		delete(t);
	}
	void reverse(){
		Node *node, *next, *prev;
		prev = NULL;
		node = head;
		while(node){
			next = node->next;
			node->next = prev;
			prev = node;
			node = next;
		}
		head = prev;
	}
	void printRec(){
		print(head);
	}
	void print(Node* p){
		if(p == NULL)return;
		print(p->next);
		cout<<p->data<<" ";
		// for normal printing, cout first then rec call
		// for reverse printing, rec call first them cout
	}
	void display(){
		Node* node = head;
		while(node->next!=NULL){
			cout<<node->data<<" ";
			node = node->next;
		}
		cout<<node->data<<"\n";
	}
};

int main(){
	
	List l;
	l.insert(0);
	l.insert(1);
	l.insert(2);
	l.insert(3);
	
	l.reverse();
	l.display();
	
	l.printRec();
	return 0;
}