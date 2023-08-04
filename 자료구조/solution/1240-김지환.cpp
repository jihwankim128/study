// acmicpc 1240
// authored by jihwankim
// 23-08-04 PM 08:54
// study
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> tree[1005];
int nodeDistance;

bool dfs(int prevNode, int parent, int findNode, int weight) {
	if(parent == findNode) {
		nodeDistance = weight;
		return true;
	} 
	for(auto child : tree[parent]) {
		if(child.first == prevNode) continue;
		if(dfs(parent, child.first, findNode, weight+child.second)) return true;
	}
	return false;
}

void solve(int node1, int node2) {
	if(dfs(0, node1, node2, 0)) {
		cout << nodeDistance << "\n";
	}
}

void input() {
	cin >> n >> m;
	int node1, node2, weight;
	for(int i = 0; i<n-1; i++) {
		cin >> node1 >> node2 >> weight;
		tree[node1].push_back({node2, weight});
		tree[node2].push_back({node1, weight});
	}
	for(int i = 0; i<m; i++) {
		cin >> node1 >> node2;
		solve(node1, node2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	
	return 0;
}
// PM 09:08
