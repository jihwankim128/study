/*
	acmicpc 18111
	authored by jihwankim
	study
	23-11-24 AM 10:27 ~ 10:59
*/

#include <bits/stdc++.h>
#define h first
#define time second

using namespace std;

int n, m, b;
int arr[500][500];
int minH = INT_MAX;
int maxH = 0;

void input() {
	cin >> n >> m >> b;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];	
			minH = min(minH, arr[i][j]);
			maxH = max(maxH, arr[i][j]);
		}
	}
}

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	if(p1.time == p2.time) {
		return p1.h > p2.h;
	}
	return p1.time < p2.time;
}

void solve() {
	vector<pair<int,int>> v;

	for(int h = minH; h <= maxH; h++) {
		int add = 0;
		int del = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int diff = arr[i][j] - h;
				
				if(diff == 0) continue;
				if(diff > 0) del += diff;
				if(diff < 0) add += abs(diff);
			}
		}
		if(add > del + b) continue;
		int time = add + del * 2;
		
		v.push_back(make_pair(h, time));
	}
	sort(v.begin(), v.end(), compare);
	cout << v[0].time << ' ' << v[0].h;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

/*
	1. 좌표 i, j의 가장 위에 있는 블록을 제거한다. -> 인벤토리에 추가 
	-> 2초 
	2. 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
	-> 1초	 
*/
