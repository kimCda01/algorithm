#include<iostream>
#include<vector>
#include<queue>

using namespace std;

short n, m;
vector<vector<short>> laboratory;
short dx[4] = { 1, -1, 0, 0 };
short dy[4] = { 0, 0, 1, -1 };

short result = 0;

void VirusCheck() {
	queue<pair<short, short>> q;
	vector<vector<short>> tempLab(n, vector<short>(m));

	tempLab = laboratory;
	for (short i = 0; i < n; i++) {
		for (short j = 0; j < m; j++) {
			if (tempLab[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		short x = q.front().first;
		short y = q.front().second;
		q.pop();
		for (short dir = 0; dir < 4; dir++) {
			short nx = x + dx[dir];
			short ny = y + dy[dir];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (tempLab[nx][ny] == 0) {
					tempLab[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
		}
	}

	short count = 0;
	for (short i = 0; i < n; i++) {
		for (short j = 0; j < m; j++) {
			if (tempLab[i][j] == 0) count++;
		}
	}

	if (result < count) {
		result = count;
	}
	
}

void AddWall(short start, short remain) {
	if (remain == 0) {
		VirusCheck();
		return;
	}

	for (short i = start; i < n * m; i++)
	{
		short x = i % m;
		short y = i / m;
		if (laboratory[y][x] == 0) {
			laboratory[y][x] = 1;
			AddWall(i + 1, remain - 1);
			laboratory[y][x] = 0;
		}
	}
}

int main() { // 0 : empty Place, 1 : wall, 2 : virus
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	laboratory.resize(n);
	for (short i = 0; i < n; i++)
	{
		for (short j = 0; j < m; j++)
		{
			short input;
			cin >> input;

			laboratory[i].push_back(input);
		}
	}

	AddWall(0, 3);
	cout << result;
}

// if data for 1 and 2 are not in the laboratory array
// O(((n^2) * (n^2-1) * (n^2-2) / 3!) * n * m)
// 2,666,496 