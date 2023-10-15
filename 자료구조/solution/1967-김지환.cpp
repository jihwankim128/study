// acmicpc 1967
// authored by jihwankim
// 23-08-04 AM 03:49
// study
#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> tree[10005];
bool visited[10005];
int MaxWeight;
int node;

void input() {
	cin >> n;
	for(int i = 0; i<n-1; i++) {
		int parent, child, weight;
		cin >> parent >> child >> weight;
		tree[parent].push_back({child, weight});
		tree[child].push_back({parent, weight});
	}
}

void dfs(int parent, int weight) {
	if(weight > MaxWeight) {
		MaxWeight = weight;
		node = parent;
	}
	visited[parent] = true;
	
	for(int i = 0; i<tree[parent].size(); i++) {
		int child = tree[parent][i].first;
		if(!visited[child]) {
			dfs(child, weight + tree[parent][i].second);
		}
	}
}

void solve() {
	dfs(1, 0);
	for(int i = 1; i<=n; i++) {
		visited[i] = false;
	} 
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
// AM 04:08
