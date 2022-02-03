
#include<iostream>
using namespace std;
#define MAX_SIZE  5

class Stack {
private:
	int A[MAX_SIZE];
	int top;
public:
	//constructor
	Stack() {
		top = -1;
	}

	void Push(int x) {
		if (top == MAX_SIZE - 1) {
			cout << "Overflow!" << endl;
			return;
		}
		A[++top] = x;
	}

	void Pop() {
		top--;
	}

	int Top() {
		return A[top];
	}

	bool IsEmpty() {
		if (top == -1) return true;
		return false;
	}

	void Print() {
		cout << "Stack:";
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}

};

void ArrayBasedStack() {
	Stack S;
	S.Push(2); S.Print();     //top = 0
	S.Push(5); S.Print();
	S.Push(10); S.Print();
	S.Pop(); S.Print();
	S.Push(12); S.Print();
	S.Push(12);
	S.Push(12); S.Print();           //top = 4
	S.Push(12); S.Print();
}

/**/