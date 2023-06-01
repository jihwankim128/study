#include <bits/stdc++.h>

using namespace std;

int board[502][502];
bool vis[502][502];
queue <pair<int, int>> draw;
int n, m;
int cnt, ma;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			/* 방문했거나  막혀있을 경우*/
			if (board[i][j] == 0 || vis[i][j]) continue;
			cnt++;
			queue <pair<int, int>> draw;
			vis[i][j] = 1;
			draw.push({ i, j });
			int area = 0;
			while (!draw.empty()) {
				area++;
				pair<int, int> cur = draw.front(); draw.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
					/* 범위 초과 할 경우 */
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					/* 길이 막혔거나 방문했을 경우 */
					vis[nx][ny] = 1;
					draw.push({ nx, ny });
				}
			}
			ma = max(ma, area);
		}
	}
	cout << cnt << '\n' << ma;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	input();
	solution();
	return 0;
}
