#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void printList(struct Node *head){

    struct Node *p = head;

    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void findMiddle(Node *cur, Node **first, Node **second){

    Node *slow = *first;
    Node *fast = *second;
    slow=cur;
    fast=cur->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=cur;
    *second=slow->next;
    slow->next=NULL;

}

Node *mergeBoth(Node *first, Node *second){

    Node *answer = NULL;

    if(!first) return second;
    else if(!second) return first;

    if(first->data <= second->data){
        answer = first;
        answer->next = mergeBoth(first->next, second);
    }else {
        answer = second;
        answer->next = mergeBoth(first, second->next);
    }

    return answer;
}

void mergeSort(struct Node **head){

    Node *cur = *head;
    Node *first;
    Node *second;

    if(!cur or !cur->next) return ;

    findMiddle(cur, &first, &second);

    mergeSort(&first);
    mergeSort(&second);

    *head = mergeBoth(first,second);

}

int main(){
    
    
    Node* first = new Node(7);
    first->next = new Node(6);
    first->next->next = new Node(5);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(3);
    first->next->next->next->next->next = new Node(2);
    first->next->next->next->next->next->next = new Node(1);

    cout<<"list = ";
    printList(first);

    cout<<"\nMerge Sort = ";
    mergeSort(&first);

    printList(first);

    return 0;
}
