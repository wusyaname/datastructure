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
	int val;        // �ڵ�ֵ
	ListNode* next; // ��̽ڵ�����
	ListNode(int x) : val(x), next(NULL) {}
};

//ListNodeβ�����ӽڵ�
void AddNode(ListNode* head, int x) {
	ListNode* creat = new ListNode(x);
	ListNode* traverse = head;
	while (traverse->next != NULL) {
		traverse = traverse->next;
	}
	traverse->next = creat;
}

//ListNodeͷ�����ӽڵ�
void Insert(ListNode** head, int x) {
	ListNode* temp = new ListNode(x);
	temp->next = *head;
	*head = temp;
}

//ListNode ��n��λ�ò���ڵ�
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





//reverse a linked list ͨ�������ķ�������������ָ��ʵ��
ListNode* Reverse(ListNode* head) {
	ListNode* prev, * current, * next;
	//������ָ��ʵ������ķ�ת  �﷨����ÿ��ָ��ǰ�涼Ҫ��*
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

//reverse a linked list by recursion �ݹ鷨
ListNode* RecursiveReverse(ListNode* head) {
	if (head->next == NULL) {
		return head;
	}
	ListNode* result = RecursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return result;
}




//����ListNode���ֵ
void PrintListNode(ListNode* head) {
	ListNode* traverse = head;
	while (traverse != NULL) {
		cout << traverse->val << " ";
		traverse = traverse->next;
	}
	cout << endl;
}

//�ݹ�˳�����ListNode��ֵ
void RecursivePrintListNode(ListNode* head) {
	if (head == NULL) return;
	cout << head->val << " ";
	RecursivePrintListNode(head->next);
}

//�ݹ鵹�����ListNode��ֵ  �ȵݹ�����ֵ���ɣ��ú���ѹջ��˼�������
void RecursiveReversePrintListNode(ListNode* head) {
	if (head == NULL) return;
	RecursiveReversePrintListNode(head->next);
	cout << head->val << " ";
}

//void test1()
//{
//	Node* A;
//	A = NULL;
//	Node* temp = (Node*)malloc(sizeof(Node));    //malloc����void���͵�ָ�룬������ǰ���ϣ�Node*������ǿ��ת��
//	temp->data = 2;
//	temp->next = NULL;
//	A = temp;
//	cout << "Malloc ����Ľڵ�����:" << A->data << endl;
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
	cout << "ͨ��loop������תһ��, �����Լ��ݹ鷽�����һ�Σ�"<< endl;
	PrintListNode(A);      // 4  3  2  10
	RecursivePrintListNode(A);
	cout << "\n " << "�������" << endl;
	RecursiveReversePrintListNode(A);
	cout << "\n" << "�ݹ鷴תһ�Σ�" << "\n";
	A = RecursiveReverse(A);
	PrintListNode(A);
	
}



/**/