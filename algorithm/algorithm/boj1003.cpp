#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> save;

pair<int, int> fibo(int num) 
{
	if (save[num].first != 0 || save[num].second != 0) {
		return save[num];
	}

	auto one = fibo(num - 1);
	auto two = fibo(num - 2);
	save[num] = { one.first + two.first, one.second + two.second };

	return save[num];
}


int main() {
	int n;
	cin >> n;

	save.resize(40);
	for (auto& p : save) {
		p = { 0,0 };
	}

	save[0] = { 1, 0 };
	save[1] = { 0, 1 };

	for (int i = 0; i < n; i++)
	{
		int start;
		cin >> start;

		auto result = fibo(start);
		cout << result.first << " " << result.second << "\n";
	}
}