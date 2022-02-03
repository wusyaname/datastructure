/**/
#include<iostream>
#include<queue>
#define INI_MIN  -100
#define INI_MAX  100
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x=0) : data(x), left(NULL), right(NULL) {}
};

//���ǱȽϵ��͵Ĵ��󣬵ݹ����ʱ��������ζ���new�µĽڵ㣬��Ȼ�ᵼ���ڴ�й¶��
//BSTNode* Insert(BSTNode* root, int data) {
//	BSTNode* temp = new BSTNode(data);                               /// �������⣡
//	if (root == NULL) {
//		root = temp;
//	}
//	else if (temp->data <= root->data) {
//		root->left = Insert(root->left, data);
//	}
//	else {
//		root->right = Insert(root->right, data);
//	}
//	return root;
//}
BSTNode* Insert(BSTNode* root, int data) {                              
	if (root == NULL) {
		BSTNode* temp = new BSTNode(data);
		root = temp;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}


//��BST�е�Ԫ��
bool Search(BSTNode* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data < root->data) return(Search(root->left, data));
	else return(Search(root->right, data));
}


//����BST�������Сֵ
int FindMax(BSTNode* root) {
	if (root == NULL) {
		cout << "Empty tree!" << endl;
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return(root->data);
}

int FindMin(BSTNode* root) {
	if (root == NULL) {
		cout << "Empty tree!" << endl;
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

//�������������ȣ���һ����BST����������
int FindHeight(BSTNode* root) {
	if (root == NULL) {
		return -1;
	}
	int LeftHeight;
	int RightHeight;
	LeftHeight = FindHeight(root->left);
	RightHeight = FindHeight(root->right);
	return ((LeftHeight > RightHeight ? LeftHeight+1 : RightHeight+1) );  //���ش�ģ�����������������������������������������������������������������������������
}

//traverse ��������������һ���Ƕ���������
//������ȣ��ö���
void LevelOrder(BSTNode* root) {
	if (root == NULL) return;
	queue<BSTNode*> Q;
	Q.push(root);

	while (!Q.empty()) {
		BSTNode* front = Q.front();
		cout << front->data << " ";
		if(front->left != NULL) Q.push(front->left);
		if (front->right != NULL) Q.push(front->right);
		Q.pop();
	}
}

//�������depth
//������� ������
void PreOrder(BSTNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
//�������
void InOrder(BSTNode* root) {
	if (root == NULL) return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}
//�������
void PostOrder(BSTNode* root) {
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}

bool IsBinaryUtil(BSTNode* root, int min, int max) {
	if (root == NULL) return true;
	if (root->data > min && root->data < max
		&& IsBinaryUtil(root->left, min, root->data)
		&& IsBinaryUtil(root->right, root->data, max)) {
		return true;
	}
	else return false;
}

bool IsBinarayTree(BSTNode* root) {
	return (IsBinaryUtil(root, INI_MIN, INI_MAX));
}

//ɾ�������������е�ֵΪdata��Ԫ��,
BSTNode* DeleteBSTNode(BSTNode* root, int data) {
	if (root == NULL) return root;
	else if (root->data < data) root->right = DeleteBSTNode(root->right, data);
	else if (root->data > data) root->left = DeleteBSTNode(root->left, data);
	else { // root->data == data
		//case1:�ýڵ�Ϊleaf node Ҷ�ڵ�
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//case2:�ýڵ�ֻ��һ������ either left or right
		else if (root->left == NULL) {
			BSTNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			BSTNode* temp = root;
			root = root->left;
			delete temp;
		}
		//case3: �ýڵ�����������
		else {
			root->data = FindMin(root->right);
			root->right = DeleteBSTNode(root->right, data);
		}
		return root;
	}
}


void BSTImplementation() {
	BSTNode* root = NULL;
	/*Code to test the logic*/


	root = Insert(root, 12);
	root = Insert(root, 5);
	root = Insert(root, 14);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 13);
	root = Insert(root, 17);
	root = Insert(root, 1);
	root = Insert(root, 9);
	root = Insert(root, 20);
	root = Insert(root, 8);
	root = Insert(root, 11);
	root = Insert(root, 18);
	int number;
	cout << "Enter number be searched:\n";
	cin >> number;
	//If number is found, print "FOUND"
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";
	cout << "max: " << FindMax(root) << "\n" << "min: " << FindMin(root) << endl;
	cout << "Height: " << FindHeight(root) << endl;
	cout << "level order:  ";
	LevelOrder(root);
	cout << endl;
	cout << "preorder:  ";
	PreOrder(root);
	cout << endl;
	cout << "inorder:  ";
	InOrder(root);
	cout << endl;
	cout << "postorder:  ";
	PostOrder(root);
	cout << endl;
	if (IsBinarayTree) cout << "It is binary search tree" << endl;
	root = DeleteBSTNode(root, 5);
	cout << root->left->data << endl;

	cout << "Enter number be searched:\n";
	cin >> number;
	//If number is found, print "FOUND"
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";
}