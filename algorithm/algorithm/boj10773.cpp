#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n, data, res = 0;
	stack<int> st;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> data;
		if (data == 0) {
			if (st.empty() == false) st.pop();
			continue;
		}
		st.push(data);
	}

	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}

	cout << res;
}
