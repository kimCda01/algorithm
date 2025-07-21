#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		queue<char> q;
		bool succ = true;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(') {
				q.push(str[j]);
			}
			else {
				if (!q.empty()) q.pop();
				else {
					succ = false;
					break;
				}
			}
		}

		if (succ) {
			succ = succ ? q.empty() : succ;
			if (succ) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		else {
			cout << "NO" << "\n";
		}

	}
}