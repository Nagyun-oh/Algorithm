#include <iostream>
#include <string>
using namespace std;

string str;
string boom;
string temp;
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> str >> boom;

	int str_len = str.length();
	int boom_len = boom.length();

	for (int i = 0; i < str.length(); i++) {
		temp += str[i];
		if (temp.length() >= boom_len) {
			 flag = true;
			 for (int j = 0; j < boom_len; j++) {
				 if (temp[temp.size() - boom_len + j] != boom[j]) {
					 flag = false;
					 break;
				 }
			 }
			 if (flag)temp.erase(temp.end() - boom_len, temp.end());		// 문자열 폭발
		}	
	}

	if (temp.empty())cout << "FRULA";
	else cout << temp;


}