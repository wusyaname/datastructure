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

//这是比较典型的错误，递归调用时，无论如何都会new新的节点，必然会导致内存泄露！
//BSTNode* Insert(BSTNode* root, int data) {
//	BSTNode* temp = new BSTNode(data);                               /// 出大问题！
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


//找BST中的元素
bool Search(BSTNode* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data < root->data) return(Search(root->left, data));
	else return(Search(root->right, data));
}


//计算BST的最大最小值
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

//计算二叉树的深度，不一定是BST二叉搜索树
int FindHeight(BSTNode* root) {
	if (root == NULL) {
		return -1;
	}
	int LeftHeight;
	int RightHeight;
	LeftHeight = FindHeight(root->left);
	RightHeight = FindHeight(root->right);
	return ((LeftHeight > RightHeight ? LeftHeight+1 : RightHeight+1) );  //返回大的！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
}

//traverse 遍历二叉树，不一定是二叉搜索树
//广度优先，用队列
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

//深度优先depth
//先序遍历 根左右
void PreOrder(BSTNode* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序遍历
void InOrder(BSTNode* root) {
	if (root == NULL) return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}
//后序遍历
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

//删除二叉搜索树中的值为data的元素,
BSTNode* DeleteBSTNode(BSTNode* root, int data) {
	if (root == NULL) return root;
	else if (root->data < data) root->right = DeleteBSTNode(root->right, data);
	else if (root->data > data) root->left = DeleteBSTNode(root->left, data);
	else { // root->data == data
		//case1:该节点为leaf node 叶节点
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//case2:该节点只有一个儿子 either left or right
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
		//case3: 该节点有两个儿子
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