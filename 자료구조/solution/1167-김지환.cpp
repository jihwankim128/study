// acmicpc 1167
// authored by jihwankim
// 23-08-04 AM 04 : 08
// study
#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> tree[100005];
bool visited[100005];
int node, MaxWeight;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		int parent, child, weight;
		cin >> parent;
		while(true) {
			cin >> child;
			if(child == -1) break;
			cin >> weight;
			tree[parent].push_back({child, weight});
		}
	}
}

void dfs(int parent, int weight) {
	if(MaxWeight < weight) {
		node = parent;
		MaxWeight = weight;
	}
	visited[parent] = true;
	for(int i = 0; i<tree[parent].size(); i++) {
		int child = tree[parent][i].first;
		if(visited[child]) continue;
		dfs(child, weight + tree[parent][i].second);
	}
}

void solve() {
	dfs(1, 0);
	for(int i = 1; i<=n; i++) visited[i] = false;
	dfs(node, 0);
	cout << MaxWeight;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// AM 04:22
