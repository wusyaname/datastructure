/*

#include<iostream>
#include<stack>
#include<string>
using namespace std;

//������
void Reverse(string &str,int n) {
	stack<char> S;
	//�ַ���str�����ַ���ջ
	for (int i = 0; i < str.size(); i++) {
		S.push(str[i]);
	}
	//�ַ���ջ���Ҹ�ֵ��str
	for (int i = 0; i < str.size(); i++) {
		str[i] = S.top();
		S.pop();
	}
}






void ReverseStrByStack() {
	string str1 = "Hello!";
	cout << str1 << endl;
	Reverse(str1, sizeof(str1));
	cout << str1 << endl;
}

/**/