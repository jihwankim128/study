// 2nd Test - 3
// start pm 7:36
#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int arr[250][250];
bool visited[250][250];
int cnt;

void input() {
	cin >> n >> r >> c;
}

void rec(int l_i, int r_i, int l_j, int r_j) {
	int i_mid = (l_i+r_i)/2;
	int j_mid = (l_j+r_j)/2;
	
	if(l_i>=r_i || l_j >= r_j) {
		if(visited[i_mid][j_mid]) return;
		arr[i_mid][j_mid] = cnt++;
		visited[i_mid][j_mid] = true;
		return;
	}
	
	rec(l_i, i_mid, l_j, r_j); 
	rec(i_mid+1, r_i, l_j, r_j);
	rec(l_i, r_i, l_j, j_mid);
	rec(l_i, r_i, j_mid+1, r_j);
}

void solve() {
	rec(0, (n*n)-1, 0, (n*n)-1);
	for(int i = 0; i<(n*n); i++) {
		for(int j = 0; j<(n*n); j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << arr[r][c];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
