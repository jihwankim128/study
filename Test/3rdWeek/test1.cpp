//23-06-30 PM 06:04
//authored by jihwankim
#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int maps[51][51];    			 //input
bool visited[51][51]; 			 //방문처리 
vector<pair<int, int> > coor;	 //방문한 전체 좌표 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// size, 최소차, 최대차, 인구 
void input() {
	cin >> n >> l >> r;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cin >> maps[i][j];
		}
	}
}

// 범위, 방문 chk 
bool valid(int &x, int &y) {
	if(x < 0 || x >= n) return true;
	if(y < 0 || y >= n) return true;
	if(visited[x][y]) return true;
	return false;
}

// 인구 이동 영역간 평균 값 
void moves(vector<pair<int, int> > &v, int sum) {
	for(int i = 0; i<v.size(); i++) {
		maps[v[i].first][v[i].second] = sum;
	}
}

//디버깅용 
void print() {
	cout << "\n";
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout << maps[i][j] << " ";
		}
		cout << "\n";
	}
}


bool bfs(int a, int b) {
	queue<pair<int, int> > q;	// bfs용 
	vector<pair<int, int> > v;	// 인구이동 평균 값 넣어줄 좌표벡터 
	v.push_back({a, b});
	q.push({a, b});
	coor.push_back({a, b});		// visited 초기화 하기 위한 좌표 
	visited[a][b] = true;
	int sum = maps[a][b];		// 인구이동 영역 간의 총 인구수 
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			// bfs 가능한지 체크 
			if(valid(nx, ny)) continue; 
			
			//두 영역의 인구차가 조건을 만족하는지 체크 
			int diff = abs(maps[x][y] - maps[nx][ny]);
			if(diff < l || diff > r) continue;
			
			visited[nx][ny] = true;
			
			sum += maps[nx][ny];
			coor.push_back({nx, ny});
			v.push_back({nx, ny});
			q.push({nx, ny});
		}
	}
	
	// 인구이동 가능한 지역이 2개 이상일 때 이동해야함. 
	if(v.size() > 1) {
		moves(v, sum/v.size());
		return true;
	}
	
	//v.size() == 1, 인구 이동 불가능. 그래서 0 리턴 
	return false;
}

//visited 초기화  
void clear() {
	for(int i= 0; i<coor.size(); i++) {
		visited[coor[i].first][coor[i].second] = false;
	}
	coor.clear();
}

void solve(int k) {
	int cnt = 0;
	
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			//방문 하지 않은 곳 중 인구이동 할 수 있는 곳이면
			//cnt ++ 
			if(!visited[i][j]) {
				cnt += bfs(i, j);
			}
		}
	}
	
	//인구 이동을 끝내고 다음 인구 이동을 위해 visited 초기화 
	clear();
	//print();
	
	//인구이동 한 적이 없으면 - 종료 조건임 
	if(cnt == 0) {
		cout << k;
		return;
	}
	
	// k+1 번째 인구이동이 가능한지 체크 
	solve(k+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve(0);
	
	return 0;
}
//06:42
