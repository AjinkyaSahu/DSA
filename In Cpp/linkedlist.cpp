#include <iostream>

using namespace std;

// template <class T>
class Node {

    public:
        Node *next;
        int data;
        int key;
    // public:
        Node(){
            next = NULL;
            key = 0;
            }
        Node(int data){
            this -> data = data; 
            next = NULL;
            key = 0;
        }
        void set_next(Node x){
            this -> next = &x;
        }
};

class LinkedList {
    private:

    public:
        Node *head;
        LinkedList(){
            head =NULL; 
        }
        LinkedList(Node *n){
            head = n;
        }
        Node* nodeExist(int k){
            Node* temp = head;
            Node* ptr = NULL;
            while (temp != NULL){
                if (temp -> key == k){
                    ptr = temp;
                }
                temp = temp -> next;
            };
            return ptr;
        }
        void append(Node *n){
            if (nodeExist(n->key)!=NULL){
                cout << "Node with the same key already exist..." << endl;
            }else {
                if (head == NULL){
                    head = n;
                    cout << "Node appended" <<endl;
                }else{
                    Node *temp = head;
                    while (temp->next!=NULL){
                        temp = temp->next;
                    }
                    temp->next = n;
                    cout << "node is added in the list..." <<endl;
                };
            };
        }

        void push(Node *n){
            if (nodeExist( n-> key)!=NULL){
                cout << "node is alreay exist with this key..." << endl;
            }else{
                n->next = head;
                head = n;
                cout << "node pushed at the beginning..." <<endl; 
            };
        }

        void insertAfter(int p, Node *n){
            Node *ptr = nodeExist(p);
            if (ptr == NULL){
                cout << "node does not exist with this key "<< p << "..." << endl;
            }else{
                if (nodeExist(n->key)!=NULL){
                    cout << "Node to insert is alreadey present... "<<endl;
                }else{
                    n-> next = ptr->next;
                    ptr ->next = n;
                    cout << "Node inserted..." << endl;   
                };
            };
        }

        void deleteByKey(int k){
            if (head==NULL){
                cout << "Linked list is already empty...." <<endl;
            }else if (head != NULL){
                if (head -> key == k){
                    head = head -> next;
                    cout << "Node is present at 1st place with the given key is unlinked form the list..." <<endl;
                }else{
                    // Node *temp = NULL;
                    Node* prev = head;
                    Node* cur = head->next;
                    while(cur != NULL){
                        if (cur->key == k){
                            break;
                        }else{
                            cur = cur->next;
                            prev = prev->next;
                        }
                    };
                    if (cur==NULL){
                        cout << "Node doesn't exist...." << endl;
                    }else{
                        prev->next = cur->next;
                        cout << "Node with the kye is unlinked form the list..." <<endl;
                    };
                }
            }
        }
        void updateNode(int k, int d){
            Node* ptr = nodeExist(k);
            if (ptr!=NULL){
                ptr -> data = d;
                cout << "Updated successfully" << endl;
            }else{
                cout << "Node does not found with the given key..." <<endl;
            };
        }

        void display(){
            if (head == NULL){
                cout<<"List is empty..." <<endl;
            }else{
                Node* temp = head; 
                cout << "************Printing of list***************" <<endl;

                while(temp!=NULL){
                    cout << " { " << temp->key << " , " << temp->data << " } " <<endl;
                    temp = temp -> next;
                }
            }
        }
};


int main(){
    LinkedList l;
    Node n1,n2,n3,n4;
    n1.data = 10;
    n2.data= 20;
    n1.next = &n2;
    l.head = &n1;

    l.append(&n1);
    l.display();



    return 0;
}