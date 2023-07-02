//acmicpc 16234
//authored by jihwankim
//23-06-29 PM 04:23
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int n, l, r;
int cont[51][51];
bool visited[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void input() {
	cin >> n >> l >> r;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cin >> cont[i][j];
		}
	}
}

bool valid(int x, int y) {
	if(x < 0 || x >= n) return false;
	if(y < 0 || y >= n) return false;
	if(visited[x][y]) return false;
	return true;
}

void moving(vector<pair<int, int> > &v, int sum) {
	sum = sum / v.size();
	for(int i = 0; i<v.size(); i++) {
		cont[v[i].x][v[i].y] = sum;
	}
}

bool lineChk(int a, int b) {
	queue<pair<int, int> > q;
	vector<pair<int, int> > v;
	q.push({a, b});
	v.push_back({a, b});
	visited[a][b] = true;
	int x, y, nx, ny, diff;
	int sum = cont[a][b];
	
	while(!q.empty()) {
		x = q.front().x;
		y = q.front().y; q.pop();
		for(int i = 0; i<4; i++) {
			nx = x+dx[i];
			ny = y+dy[i];
			if(!valid(nx, ny)) continue;
			diff = abs(cont[x][y]-cont[nx][ny]);
			if(diff < l || diff > r) continue; 
			visited[nx][ny] = true;
			sum += cont[nx][ny];
			q.push({nx, ny});
			v.push_back({nx, ny});
		}
	}
	if(sum == cont[a][b]) return false;
	
	moving(v, sum);
	return true;
}

void solve(int k) {
	int cnt =  0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			visited[i][j] = false;
		}
	}
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(!visited[i][j]) {		
				cnt += lineChk(i, j);
			}
		}
	}
	cout << "\n";
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout << cont[i][j] << " ";
		}
		cout << "\n";
	}
	if(cnt == 0) {
		cout << k;
		return ;
	}
	solve(k+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve(0);
	
	return 0;
}

// PM 04:48
