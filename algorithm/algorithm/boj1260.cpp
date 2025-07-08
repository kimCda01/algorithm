#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> vec;
vector<bool> visit;
void DFS(int num) {
	visit[num] = true;
	cout << num << " ";
	for (int i = 0; i < vec[num].size(); i++)
	{
		int next = vec[num][i];
		if (visit[next] == false) {
			DFS(next);
		}
	}
}

void BFS(int num) {
	queue<int> q;
	q.push(num);

	visit[num] = true;

	while (!q.empty())
	{
		int front = q.front();
		cout << front << " ";
		q.pop();

		for (int i = 0; i < vec[front].size(); i++)
		{
			int next = vec[front][i];
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	vec.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		vec[node1].push_back(node2);
		vec[node2].push_back(node1);
	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	DFS(v);
	cout << "\n";

	visit.clear();
	visit.resize(n + 1);
	BFS(v);
}

