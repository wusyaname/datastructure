/**/
#include<iostream>
#define MAX_SIZE 101
using namespace std;


class Queue {
private:
	int A[MAX_SIZE];
	int front;
	int rear;
public:
	Queue() {
		front = -1;
		rear = -1;
	}

	bool IsEmpty() {
		return (front == -1 && rear == -1);
	}

	bool IsFull() {
		return((rear + 1) % MAX_SIZE == front);
	}

	int getfront() {
		return A[front];
	}

	int getrear() {
		return A[rear];
	}

	//出队列
	void Dequeue() {
		cout << "Dequeuing..\n";
		if (IsEmpty()) {
			cout << "The queue is empty;";
			return;                    //返回啥？
		}
		//关键一步
		if (front == rear) {
			front = rear = -1;
			return ;
		}
		front = (front + 1) % MAX_SIZE;
	}

	//入队列
	void Enqueue(int x) {
		cout << "Enqueuing " << x << endl;
		if (IsFull()) {
			cout << "The queue is full!" << endl;
			return;
		}
		else if (IsEmpty()) front = rear = 0;
		else rear = (rear + 1) % MAX_SIZE;
		A[rear] = x;
		return;
	}

	void Print()
	{
		if (IsEmpty()) {
			cout << "The queue is empty!" << endl;
			return;
		}
		// Finding number of elements in queue  
		int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;    //关键一步计算元素个数
		for (int i = 0; i < count; i++) {
			cout << A[(i + front) % MAX_SIZE] << " ";
		}
		cout << endl;
	}
	
};

void ArrayBasedQueue() {
	//Driver Code to test the implementation
  //Printing the elements in Queue after each Enqueue or Dequeue

	Queue Q; // creating an instance of Queue. 
	Q.Enqueue(2);  Q.Print();
	Q.Enqueue(4);  Q.Print();
	Q.Enqueue(6);  Q.Print();
	Q.Dequeue();   Q.Print();
	Q.Enqueue(8);  Q.Print();
}

/**/