#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	string res = "";
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		if (value == 0) {
			if (pq.empty()) {
				res += "0\n";
			}
			else {
				res += to_string(pq.top()) + "\n";
				pq.pop();
			}
			continue;
		}

		pq.push(value);
	}

	cout << res;
}