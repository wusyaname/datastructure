/*
#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL) {}
};
Node* front = NULL;   //Á´±íÍ·
Node* rear = NULL;



bool IsEmpty() {
	return(front == NULL && rear == NULL);
}

int Front() {
	if (IsEmpty()) {
		cout << "The queue is empty!" << endl;
		return -1;
	}
	return front->val;
}

void Enqueue(int x) {
	Node* temp = new Node(x);
	if (IsEmpty()) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	if (IsEmpty()) {
		cout << "The queue is empty!" << endl;
		return;
	}
	Node* temp = front;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	delete temp;
	return;
}

void Print() {
	if (front == NULL && rear == NULL) {
		cout << "empty!" << endl;
		return;
	}
	Node* temp = front;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}


void LinkedListBasedQueue() {
	Enqueue(2); Print();
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}

/**/