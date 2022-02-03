
#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x): val(x), next(NULL){}
};

Node* top = NULL;

//满足时间复杂度O1，从头部插入！！！
void Push(int x) {
	Node* temp = new Node(x);
	//Node* temp = (Node*)malloc(sizeof(Node));
	temp->next = top;
	top = temp;
}

void pop() {
	if (top == NULL) return;
	Node* temp = top;
	top = top->next;
	delete temp;
}

void LinkedListBasedStack() {

}

/**/