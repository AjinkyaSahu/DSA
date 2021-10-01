#include<bits/stdc++.h>
using namespace std;
int arr[100],n,front,rear;
void enqueue(int num){
    if(rear!=n)
    {

        arr[rear]=num;
        rear++;
    }
    else{
        cout<<"queue overflow!\n";
    }
    
}
void dequeue(){
    if(front==rear)
    {
        cout<<"underflow\n";
    }
    else{
        arr[front]=0;
        front++;
    }
}
void display(){
    if(front==rear)
    {
        cout<<"underflow\n";
    }
    int i;
    for(i=front;i<rear;i++)
    cout<<arr[i]<<" ";
}
int main(){
    int ch,i,ele;
    cin>>n;
    cout<<"enter yr choice\n";
    cin>>ch;
    front=rear=0;
    while(ch!=0){
    switch(ch)
    {
    case 0:
        exit(0);
    case 1:
        cin>>ele;
        enqueue(ele);
        break;
    case 2:
        dequeue();
        break;
    case 3:
    display();
    break;
    default:
        break;
    }
    cout<<"enter yr choice\n";
    cin>>ch;
    }
}
