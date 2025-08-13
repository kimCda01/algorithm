#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int FindDestination(const vector<vector<int>>& v) {
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, 0)));

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int broke = get<2>(q.front());
        q.pop();

        if (y == n - 1 && x == m - 1) {
            return visited[y][x][broke];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            // 벽이 아닌 경우
            if (v[ny][nx] == 0 && visited[ny][nx][broke] == 0) {
                visited[ny][nx][broke] = visited[y][x][broke] + 1;
                q.push(make_tuple(ny, nx, broke));
            }
            // 벽이고, 아직 벽을 부수지 않은 경우
            else if (v[ny][nx] == 1 && broke == 0 && visited[ny][nx][1] == 0) {
                visited[ny][nx][1] = visited[y][x][broke] + 1;
                q.push(make_tuple(ny, nx, 1));
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            v[i][j] = row[j] - '0';
        }
    }

    cout << FindDestination(v);
}
