//acmicpc 18808
//authored by jihwankim
//2023-06-08 PM 12:20

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int n, m, k;
int stickers[101][41][41];
int arr[41][41];
int maxCnt;
int kcnt;
vector<pair<int, int> > sticker_size;

void input() {
	cin >> n >> m >> k;
	int r, c;
	for(int i=0; i<k; i++) {
		cin >> r >> c;
		sticker_size.push_back({r, c});
		for(int j = 0; j<r; j++) {
			for(int z = 0; z<c; z++) {
				cin >> stickers[i][j][z];
			}
		}
	}	
}

// 시계방향 90도 회전 
void rotate(int arr1[41][41], int arr2[41][41], int &x, int &y) {
	for(int i = 0; i<y; i++) {
		for(int j = 0; j<x; j++) {
			arr1[i][j] = arr2[x-j-1][i];
		}
	}
}

void copy(int arr1[41][41], int arr2[41][41], int &x, int &y) {
	for(int i = 0; i<x ;i++) {
		for(int j = 0; j<y; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// 배열 출력 debugging 용 
void print(int arr[41][41], int &x, int &y) {
	for(int i = 0; i<x ;i++) {
		for(int j = 0; j<y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
}

// 범위 내 체크 
bool vaild(int &x, int &y) {
	if(x > n || y > m) return true;
	return false;
}

// 가지치기, 붙일 수 있는 스티커인지 check 
bool promising(int note[41][41], int sticker[41][41], int nx, int ny, int x, int y) {
	for(int i = 0; i<x; i++) {
		for(int j = 0; j<y; j++) {
			if(i >= x || j >= y) continue;
			if(note[i+nx][j+ny] == 1 && sticker[i][j] == 1) return false;
			if(note[i+nx][j+ny] == 0 && sticker[i][j] == 1){
				note[i+nx][j+ny] = sticker[i][j];
			}
		}
	}
	return true;
}

void solve(int note[41][41], int idx) {
	// k 번 스티커를 다 시도했을 경우 
	if(idx == k) {
		kcnt++;
		int cnt = 0;
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				if(note[i][j]) cnt++;
			}
		}
		maxCnt = max(maxCnt, cnt);
		return ;
	}
	
	int x = sticker_size[idx].x; 
	int y = sticker_size[idx].y;
	int nsticker[41][41];
	int nnote[41][41];
	copy(nnote, note, n, m);
	
	for(int z = 0; z<4; z++){
		//90도 씩 회전 
		if(z>0) {
			copy(nsticker, stickers[idx], x, y);
			rotate(stickers[idx], nsticker, x, y);
			swap(x, y);		
		}
		
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				int nx = i+x, ny = j+y;
				if(vaild(nx, ny)) continue;
				if(promising(nnote, stickers[idx], i, j, x, y)) {
					//print(nnote, n, m);
					solve(nnote, idx+1);
					return;
				}
				copy(nnote, note, n, m);
			}
		}
	}
	solve(note, idx+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve(arr, 0);
	cout << maxCnt << "\n";
	
	return 0;
}

// PM 03:20
