#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<bool> visited;
vector<int> path;
vector<int> ans;

void Dfs(int u, int d) {
	visited[u] = true;
	path.push_back(u + 1);
	if (u == d) {
		ans = path;
	} else {
		for (int v : a[u]) {
			if (!visited[v]) {
				Dfs(v, d);
			}
		}
	}
	visited[u] = false;
	path.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	// view the image in this repository for better understanding
	// create a graph and find the path from router 1 to router n (using DFS)
	a = vector<vector<int>>(n);
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		--p[i];
		a[p[i]].push_back(i);
	}
	visited = vector<bool>(n, false);
	Dfs(0, n - 1);
	for (auto& e : ans) {
		cout << e << " ";
	}
	cout << '\n';
	return 0;
}
