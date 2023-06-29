// acmicpc.net/problem/10026
// authored by kimjihwan
// 2023-05-31 PM 05:03

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int n, m;
char arr[101][101];
bool visited_1[101][101];
bool visited_2[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void input() {
	string s;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> s;
		for(int j = 0; j<n; j++) {
			arr[i][j] = s[j];
		}
	}
}

void bfs(int a, int b, bool chk) {
	queue<pair<int, int> > q;
	q.push({a, b});
	char c = arr[a][b];
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y; q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n) continue;
			if(ny < 0 || ny >= n) continue;
			if(chk) {
				if(visited_2[nx][ny]) continue;
				if(c=='B' && arr[nx][ny] != c) continue;
				if(c!='B' && arr[nx][ny] == 'B') continue;
				visited_2[nx][ny] = true;
				q.push({nx, ny});
			}
			else {
				if(visited_1[nx][ny]) continue;
				if(c != arr[nx][ny]) continue;
				visited_1[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}	
}

void solve() {
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(!visited_1[i][j]) {
				bfs(i, j, false);
				cnt1++;
			}
			if(!visited_2[i][j]) {
				bfs(i, j, true);
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
//PM 5:22
