#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    while (n--) {
        int cnt;
        cin >> cnt;

        unordered_map<string, int> mp;

        for (int i = 0; i < cnt; i++) {
            string str, parts;
            cin >> str >> parts;
            mp[parts]++;
        }

        int res = 1;
        for (auto& value : mp) {
            res *= (value.second + 1);
        }

        cout << res - 1 << "\n";
    }
}
