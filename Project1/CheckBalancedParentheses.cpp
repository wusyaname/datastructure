/*

#include<iostream>
#include<stack>
#include<string>
using namespace std;


//判断两个括弧是一对
bool Ispair(char a, char b) {
	if (a == '(' && b == ')') return true;
	if (a == '[' && b == ']') return true;
	if (a == '{' && b == '}') return true;
	return false;
}


bool CheckBalancedParentheses(string str) {
	stack<char> S;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			S.push(str[i]);
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (!S.empty() && Ispair(S.top(),str[i])) {
				S.pop();
			}
			else return false;
		}
	}
	if (!S.empty()) return false;
	return true;
}

void testCheckBalancedParentheses() {
	cout << "Enter your string with some ( { [:" << endl;
	string str1;
	cin >> str1;
	if (CheckBalancedParentheses(str1)) {
		cout << "Balanced!" << endl;
		return;
	}
	cout << "Not Balanced!" << endl;

}

/**/