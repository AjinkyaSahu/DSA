#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *next, *prev;
};

int main()
{
	int i,n;
	node *p, *q, *head, *temp;

	cout<<"Enter number of nodes: ";
	cin>>n;

	q = new node;
	cout<<"Enter 1st node data: ";
	cin>>q->data;
	q->next = NULL;
	head = q;

	p = head;
	for(i = 1; i < n; i++)
	{
		q = new node;
		cout<<"Enter next node data: ";
		cin>>q->data;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}

	p = head;

	cout<<"\nLinked List node data: ";

	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}

	p = head;

	p->prev = NULL;

	while(p->next != NULL)
	{
		temp = p;
		p = p->next;
		p->prev = temp;
	}

	head = p;

	cout<<"\nReverse Linked list:   ";

	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->prev;
	}

	return 0;
}
