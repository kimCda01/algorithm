#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> res;
    vector<vector<int>> v(n + 1);
    vector<int> checkV(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        checkV[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (checkV[i] == 0) {
            q.push(i);
        }
    }


    while (!q.empty()) {
        int now = q.front();
        q.pop();
        res.push_back(now);

        for (int next : v[now]) {
            checkV[next]--;
            if (checkV[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
