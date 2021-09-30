#include <iostream>

using namespace std;

class Queue
{
	private:
		int max_size;
		int arr[5];
		int rear,front;
	
	public:
		Queue(int size){
			front = -1;
			rear = -1;
			max_size = size;
			// arr[max_size];
			for(int i=0;i<5;i++){
				arr[i] = 0;
			};
		}
		bool isEmpty(){
			if (rear == -1 && front == -1){
				return true;
			}else {
				return false;
			};
		}
		bool isFull(){
			if (rear==4){
				return true;
			}else {
				return false;
			};
		}
		void enqueue(int value){
			if (isFull()){
				cout << "Queue is full you can not enter more element"<< endl;
			}else if (isEmpty()){
				cout << "The value " << value << " is entered at 0th position." << endl;
				arr[0] = value;
				front = rear = 0;
			}else {
				rear++;
				arr[rear] = value;
				cout << "The value " << value << " is entered at "<< rear <<" position." << endl;
			};
		}
		int dequeue(void){
			int x;
			if (isEmpty()){
				cout << "Queue is empty."<< endl;
				return 0;
			}else if (front == rear) {
				x = arr[front];
				arr[front] = 0;
				rear = front = -1;
				return x;
			}else{
				x = arr[front];
				arr[front] = 0;
				front++;
				return x;
			};
		}
		int count(void){
			return (rear-front+1);
		}
		void display(void){
			for (int i=0 ; i<5;i++)
				cout << arr[i] << endl;
		}
};



int main(){

	Queue q1(5),q2(5);
	cout << "starting" << endl;
	q1.display();
	cout << q1.dequeue() << endl;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.count();
	q1.display();

	q1.enqueue(40);
	q1.dequeue();
	q1.enqueue(50);

	q1.display();

	q1.enqueue(70);
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	q1.display();



    return 0;
}