//acmicpc 15686
// athored by jihwankim
// 2023-06-09 PM 02:04 

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int n, m;
int arr[51][51];
bool visited[14];
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
int openChicken = INT_MAX;

void input() {
	int num;
	cin >> n >> m;
	for(int i= 0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> num;
			if(num == 1) {
				house.push_back({i, j});
				arr[i][j] = INT_MAX;
			}
			if(num == 2) {
				chicken.push_back({i, j});
			}
		}
	}
}

void copy(int arr1[51][51], int arr2[51][51]) {
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void print(int parr[51][51]) {
	cout << "\n";
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout << parr[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve(int dist[51][51], int idx, int k) {
	if(k == m) {
		int cnt = 0;
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {
				cnt+=dist[i][j];
			}
		}
		openChicken = min(openChicken, cnt);
		return ;
	}
	if(idx == chicken.size()) return ;
	int update[51][51];
	copy(update, dist);
	
	for(int i = 0; i<house.size(); i++) {
		int dx = abs(chicken[idx].x-house[i].x);
		int dy = abs(chicken[idx].y-house[i].y);
		int d = dx+dy;
		
		update[house[i].x][house[i].y] = min(update[house[i].x][house[i].y], d);
	//	print(update);
	}
	
	solve(dist, idx+1, k);
	solve(update, idx+1, k+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve(arr, 0, 0);
	cout << openChicken;
	
	return 0;
}
// PM 2:43
