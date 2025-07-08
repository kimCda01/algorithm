#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> v;
vector<int> result;
int main() {
    int n;

    cin >> n;

    result.resize(n);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        v.push_back({ value, i });
    }

    stable_sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
        });

    for (int i = 0; i < v.size(); i++)
    {
        int index = v[i].second;
        result[index] = i;
    }

    for (auto value : result) {
        cout << value << " ";
    }
}
// 3
// 2(0) 3(1) 1(2)
// 1(2) 2(0) 3(1)
// 1 2 0