#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	map<int, int> mp;
	vector<int> v;
	cin >> n;

	int min = 4001, max = -4001;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		sum += input;
		if (min > input) min = input;
		if (max < input) max = input;

		mp[input]++;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	vector<pair<int, int>> vec(mp.begin(), mp.end());
	stable_sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
		});
	int maxFreq = vec[0].second;
	vector<int> freq;
	for (auto& value : vec) {
		if (value.second == maxFreq)
			freq.push_back(value.first);
		else
			break;
	}
	if (freq.size() == 1) {
		maxFreq = freq[0];
	}
	else {
		maxFreq = freq[1];
	}

	cout << (int)round((double)sum / n) << "\n";
	cout << v[v.size() / 2] << "\n";
	cout << maxFreq << "\n";
	cout << max - min;
}