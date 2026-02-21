#include <iostream>
#include <stack>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cout.tie(0);

	string str;
	stack<char> st;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {

		// 피연산자
		if (str[i] >= 65 && str[i] <= 90) {
			cout << str[i];
			continue;
		}

		//연산자 : ( , )   +,-    *,/

		if (str[i] == '(')st.push(str[i]);
		else if (str[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '*' || str[i] == '/') {
			while ((!st.empty())&& (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}