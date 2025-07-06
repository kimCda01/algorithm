#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, result = 0;
	deque<int> dq;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		dq.push_back(i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		auto iter = std::find(dq.begin(), dq.end(), num);

		// 에러나면 위에서 뭔가 잘못된거임
		int index = std::distance(dq.begin(), iter);
		int dqSize = dq.size();
		int centerIndex = dqSize / 2;

		bool isLeft = index <= centerIndex;
		while (dq.front() != num)
		{
			if (isLeft) {
				auto front = dq.front();
				dq.pop_front();
				dq.push_back(front);
			}
			else {
				auto front = dq.back();
				dq.pop_back();
				dq.push_front(front);
			}
			result++;
		}

		dq.pop_front();
	}

	cout << result;
	return 0;
}
