#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *next, *prev;
	Node(int d){
		data = d;
		next = NULL;
		prev = NULL;
	}
};

class DList{
	Node* head;
public:
	DList(){
		head = NULL;
	}
	void insertNodeH(int d){
		Node* node = new Node(d);
		if(head==NULL){
			cout<<d<<"\n";
			head = node;
		}else {
			node->next = head;
			head->prev = node;
			head = node;
		}
	}
	void insertNodeT(int d){
		Node* node = new Node(d);
		if(head==NULL){
			cout<<d<<"\n";
			head = node;
		}else {
			Node* temp = head;
			while(temp->next){
				temp = temp->next;
			}
			temp->next = node;
			node->prev = temp;
		}
	}
	void printList(){
		Node* temp = head;
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
};

int main(){
	DList dl;
	dl.insertNodeH(1);
	dl.insertNodeH(2);
	dl.insertNodeT(2);
	
	dl.printList();
}