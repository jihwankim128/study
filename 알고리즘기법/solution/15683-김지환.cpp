//acmicpc 15683
// athored by jihwankim
// 2023-06-08 PM 10:39

#include <bits/stdc++.h>

using namespace std;

int n, m;
int cctv;
int minBlind = INT_MAX; 
int arr[10][10];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void input() {
	cin >> n>> m;
	for(int i =0 ; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] > 0 && arr[i][j] < 6) cctv++;
		}
	}
}

bool valid(int off[10][10], int &x, int &y) {
	if(x < 0 || x>=n) return false;
	if(y < 0 || y>=m) return false;
	if(off[x][y] == 6) return false;
	return true;
}

//감시 영역 
void move(int office[10][10], int dir, int x, int y) {
	office[x][y] = -1;
	while(valid(office, x, y)) {
		x += dx[dir];
		y += dy[dir];
		if(!valid(office, x, y)) return;
		if(office[x][y] > 0) continue;
		else office[x][y] = -1;
	}
}

void copy(int arr1[10][10], int arr2[10][10]) {
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void print(int parr[10][10]) {
	cout << "\n";
	for(int i =0 ; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cout << parr[i][j] << " ";
		}
		cout << "\n";
	}
}

//브루트포스 
void solve(int office[10][10], int cnt) {
	if(cnt == cctv) {
		int blindSpot = 0;
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				if(office[i][j] == 0) blindSpot++;
			}
		}
		
		minBlind = min(minBlind, blindSpot);
		return;
	}
	int noffice[10][10];
	copy(noffice, office);
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			//카메라 
			if(noffice[i][j] == 1) {
				for(int k = 0; k<4; k++) {
					move(noffice, k, i, j);
					//print(noffice);
					solve(noffice,  cnt+1);
					noffice[i][j] = office[i][j];
					copy(noffice, office);		
				}
				return;
			}
			if(noffice[i][j] == 2) {
				for(int k = 0; k< 2; k++) {
					move(noffice, k, i, j);
					move(noffice, (k+2)%4, i, j);
					//print(noffice);
					solve(noffice, cnt+1);
					noffice[i][j] = office[i][j];
					copy(noffice, office);
				}
				return;
			}
			if(noffice[i][j] == 3) {
				for(int k = 0; k<4; k++) {
					move(noffice, k, i, j);
					move(noffice, (k+1)%4, i, j);
					//print(noffice);
					solve(noffice, cnt+1);
					noffice[i][j] = office[i][j];
					copy(noffice, office);
				}
				return;
			}
			if(noffice[i][j] == 4) {
				for(int k = 0; k<4; k++) {
					move(noffice, k, i, j);
					move(noffice, (k+1)%4, i, j);
					move(noffice, (k+2)%4, i, j);
					//print(noffice);
					solve(noffice, cnt+1);
					noffice[i][j] = office[i][j];
					copy(noffice, office);
				}
				return;
			}
			if(noffice[i][j] == 5){
				for(int k = 0; k<4; k++) move(noffice, k, i, j);
				//print(noffice);
				solve(noffice, cnt+1);
                noffice[i][j] = office[i][j];
				copy(noffice, office);
				return;
			}
		}
	}
} 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve(arr, 0);
	cout << minBlind;
	
	return 0;
}


/*
6 6
0 0 0 0 0 0
0 2 0 0 0 0
0 0 2 0 0 0
0 0 0 2 0 0
0 0 0 0 2 0
0 0 0 0 0 0

6 6
0 0 0 0 0 0
0 3 0 0 0 0
0 0 3 0 0 0
0 0 0 3 0 0
0 0 0 0 3 0
0 0 0 0 0 0

6 6
0 0 0 0 0 0
0 4 0 0 0 0
0 0 4 0 0 0
0 0 0 4 0 0
0 0 0 0 4 0
0 0 0 0 0 0

8 8
0 0 0 0 0 0 0 0
0 1 0 2 0 3 0 0
0 0 1 0 0 0 0 0
0 0 0 2 0 0 0 0 
0 4 0 0 3 0 5 0 
0 0 0 0 0 4 0 0 
0 0 0 0 0 0 5 0 
0 0 0 0 0 0 0 0

8 8
1 0 2 0 3 0 4 0
0 0 0 0 0 0 0 5
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 2 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 3

8 8
3 0 2 0 1 0 5 0
0 0 0 0 0 0 0 4
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 3 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 2 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1

8 8
0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
0 2 0 0 5 0 0 0
0 0 3 0 0 5 0 0 
0 0 0 4 0 0 0 0 
0 0 0 0 3 0 0 0 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0

8 8
0 0 0 0 0 5 0 0
0 1 0 0 0 0 0 0
0 2 0 0 0 0 0 0
0 3 0 0 0 0 0 0 
0 4 0 0 0 0 0 0 
0 5 0 0 0 0 0 0 
0 0 0 0 0 0 4 0 
0 0 0 0 0 0 0 5
*/
// AM 1:17
