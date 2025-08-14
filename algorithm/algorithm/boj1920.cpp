#include<iostream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	set<int> st;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;

		st.insert(value);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int value;
		cin >> value;

		cout << ((st.find(value) == st.end()) ? 0 : 1) << "\n";
	}
}