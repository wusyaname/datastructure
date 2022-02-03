/*


#include<iostream>
#include<string>
#include<vector>
using namespace std;




//struct Node
//{
//	int data;
//	Node* next;
//};

struct ListNode {
	int val;        // 节点值
	ListNode* next; // 后继节点引用
	ListNode(int x) : val(x), next(NULL) {}
};

//ListNode尾部增加节点
void AddNode(ListNode* head, int x) {
	ListNode* creat = new ListNode(x);
	ListNode* traverse = head;
	while (traverse->next != NULL) {
		traverse = traverse->next;
	}
	traverse->next = creat;
}

//ListNode头部增加节点
void Insert(ListNode** head, int x) {
	ListNode* temp = new ListNode(x);
	temp->next = *head;
	*head = temp;
}

//ListNode 第n个位置插入节点
void Insert(ListNode** head, int x, int n) {
	ListNode* temp = new ListNode(x);
	if (n == 1) {
		temp->next = *head;
		*head = temp;
		return;
	}
	ListNode* temp1 = *head;
	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp1->next = temp;

}

//delete at  position n 
void Delete(ListNode** head, int n) {
	ListNode* temp1 = *head;
	if (n == 1) {
		*head = temp1->next;
		delete temp1;
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
		//temp1 points to n-1 
	}
	ListNode* temp2 = temp1->next;
	//temp2 points to n
	temp1->next = temp2->next;
	delete temp2;
}





//reverse a linked list 通过遍历的方法，利用三个指针实现
ListNode* Reverse(ListNode* head) {
	ListNode* prev, * current, * next;
	//用三个指针实现链表的反转  语法方面每个指针前面都要加*
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

//reverse a linked list by recursion 递归法
ListNode* RecursiveReverse(ListNode* head) {
	if (head->next == NULL) {
		return head;
	}
	ListNode* result = RecursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return result;
}




//遍历ListNode输出值
void PrintListNode(ListNode* head) {
	ListNode* traverse = head;
	while (traverse != NULL) {
		cout << traverse->val << " ";
		traverse = traverse->next;
	}
	cout << endl;
}

//递归顺序输出ListNode的值
void RecursivePrintListNode(ListNode* head) {
	if (head == NULL) return;
	cout << head->val << " ";
	RecursivePrintListNode(head->next);
}

//递归倒序输出ListNode的值  先递归后输出值即可，用函数压栈的思想来理解
void RecursiveReversePrintListNode(ListNode* head) {
	if (head == NULL) return;
	RecursiveReversePrintListNode(head->next);
	cout << head->val << " ";
}

//void test1()
//{
//	Node* A;
//	A = NULL;
//	Node* temp = (Node*)malloc(sizeof(Node));    //malloc返回void类型的指针，所以在前加上（Node*）进行强制转换
//	temp->data = 2;
//	temp->next = NULL;
//	A = temp;
//	cout << "Malloc 申请的节点数据:" << A->data << endl;
//}

void LinkList()
{
	ListNode* A = NULL;
	ListNode* temp = new ListNode(2);
	A = temp;
	//PrintListNode(A);
	AddNode(A, 3);
	AddNode(A, 4);
	//PrintListNode(A);
	Insert(&A, 1);
	//PrintListNode(A);
	Insert(&A, 10, 2);
	PrintListNode(A); // 1, 10, 2, 3, 4
	Delete(&A, 1);
	PrintListNode(A); //10  2  3  4  
	A = Reverse(A);   
	cout << "通过loop方法反转一次, 遍历以及递归方法输出一次："<< endl;
	PrintListNode(A);      // 4  3  2  10
	RecursivePrintListNode(A);
	cout << "\n " << "反向输出" << endl;
	RecursiveReversePrintListNode(A);
	cout << "\n" << "递归反转一次：" << "\n";
	A = RecursiveReverse(A);
	PrintListNode(A);
	
}



/**/