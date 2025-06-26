#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

bool sortFunc(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main() {
	int n, result = 0;
	vector<pair<int, int>> v;

	cin >> n;

	// input
	for (int i = 0; i < n; i++)
	{
		int input1, input2;
		cin >> input1 >> input2;

		v.push_back({ input1, input2 });
	}
	sort(v.begin(), v.end(), sortFunc);

	// logic
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		if (st.empty() || v[i].first >= st.top()) {
			st.push(v[i].second);
			result++;
			continue;
		}
	}

	cout << result;

	return 0;
}