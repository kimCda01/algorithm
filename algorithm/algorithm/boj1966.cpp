#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int T, n, idx, value;
	cin >> T;

	while (T--)
	{
		queue<pair<int, int>> q;
		vector<int> v;
		cin >> n >> idx;

		for (int i = 0; i < n; i++)
		{
			cin >> value;
			q.push({ value, i });
			v.push_back(value);
		}

		sort(v.begin(), v.end(), greater<int>());

		int res = 0;
		while (!q.empty())
		{
			int target = v[0];
			int front = q.front().first;
			int findIdx = q.front().second;
			if (front == target) {
				res++;
				v.erase(v.begin());
				if (findIdx == idx) {
					break;
				}
			}
			
			q.pop();
			q.push({front, findIdx});
		}
		cout << res << "\n";
	}
}