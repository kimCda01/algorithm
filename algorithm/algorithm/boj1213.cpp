#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;

int main() {
	string str, error = "I'm Sorry Hansoo";
	cin >> str; // 공백 없으니 괜찮을거임

	map<char, int> mp;
	for (char value : str) {
		mp[value]++;
	}

	int oddCnt = 0;
	char oddChar = ' ';
	for (auto value : mp) {
		if (value.second % 2 == 0) continue;


		oddChar = value.first;
		oddCnt++;
	}
	if (oddCnt > 1) {
		cout << error;
		return 0;
	}

	stack<char> st;
	for (auto data : mp) {
		for (int i = 0; i < data.second / 2; i++)
		{
			cout << data.first;
			st.push(data.first);
		}
	}
	if (oddChar != ' ') {
		cout << oddChar;
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

