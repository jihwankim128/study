// acm 11559
// authored by jihwankim
// 2023-06-14 AM 12:10

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

char arr[12][6];
bool visited[12][6];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void input() {
	for(int i = 0; i<12; i++) {
		for(int j = 0; j<6; j++) {
			cin >> arr[i][j];
		}
	}
}

void clearVisited() {
	for(int i = 0; i<12; i++) {
		for(int j =0 ; j<6; j++) {
			visited[i][j] = false;
		}
	}
}

bool vaild(int &x, int &y) {
	if(x<0 || x>=12) return true;
	if(y<0 || y>=6) return true;
	if(visited[x][y]) return true;
	return false;
}

void print() {
	for(int i = 0; i<12; i++) {
		for(int j = 0; j<6; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
void puyopuyo() {
	queue<char> q;
	
	for(int i = 0; i<6; i++) {
		for(int j = 11; j>=0; j--){
			if(arr[j][i] != '.') {
				q.push(arr[j][i]);
				arr[j][i] = '.';
			}
		}
		int idx = 11;
		while(!q.empty()) {
			arr[idx][i] = q.front();
			idx -= 1;
			q.pop();
		}
	}
}

bool bfs(pair<int, int> xy) {
	clearVisited();
	
	queue<pair<int, int> > q;
	vector<pair<int, int> > v;
	char ch = arr[xy.x][xy.y];
	int cnt = 0;
	
	visited[xy.x][xy.y] = true;
	q.push(xy);
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y; q.pop();
		v.push_back({x, y});
		cnt++;
		
		for(int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(vaild(nx, ny)) continue;
			if(ch != arr[nx][ny]) continue;
			
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	
	if(cnt >= 4) {
		for(int i = 0; i<v.size(); i++) {
			int x = v[i].x;
			int y = v[i].y;
			arr[x][y] = '.';
		}
		return true;	
	}
	return false;
}

void solve(int cnt) {
	int boom = 0;
	for(int i = 0; i<12; i++) {
		for(int j = 0; j<6; j++) {
			if(arr[i][j] != '.') {
				if(bfs({i, j})) {
					boom++;
				}
			}
		}
	}
	if(boom == 0) cout << cnt;
	else {
		puyopuyo();
		solve(cnt+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve(0);
	
	return 0;
}

/*
해결책 접근
1. BFS 시작 지점으로 부터 상하좌우를 탐색한다.
2. BFS 시작 지점과 같은 문자가 4개 이상 있으면 모두 제거한다. '.'
3. 모든 '.' 위에 있는 문자를 내린다. 
4. 1번부터 3번을 반복한다. (재귀 함수) 

*/

//AM 12:50
