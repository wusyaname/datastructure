/*

#include<iostream>
#include<stack>
#include<string>
using namespace std;

//传引用
void Reverse(string &str,int n) {
	stack<char> S;
	//字符串str所有字符入栈
	for (int i = 0; i < str.size(); i++) {
		S.push(str[i]);
	}
	//字符出栈并且赋值给str
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