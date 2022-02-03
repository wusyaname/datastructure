/*

#include <iostream>
#include <string>
using namespace std;

struct DbListNode {
	int val;
	DbListNode* next;
	DbListNode* prev;
	DbListNode(int x) : val(x), next(NULL), prev(NULL){}
};

DbListNode* head = NULL;

void InsertAtHead(int x) {
	DbListNode* temp = new DbListNode(x);
	if (head == NULL) {
		head = temp;
		return;
	}
	temp->next = head;
	head->prev =temp;
	head = temp;
}

void Print() {
	cout << "正向输出：";
	DbListNode* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

void ReversePrint() {
	cout << "反向输出: ";
	DbListNode* temp = head;
	if (temp == NULL) return;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->prev;
	}
	cout << endl;
}

void DoublyLinkedList() {
	InsertAtHead(1);
	InsertAtHead(2);
	InsertAtHead(3);
	InsertAtHead(4);
	InsertAtHead(5);   //  5   4  3    2  1
	Print();
	ReversePrint();
}

/**/