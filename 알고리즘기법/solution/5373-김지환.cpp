//acmicpc 5373
//authored by jihwankim
//23-07-01 AM 03:19

#include <bits/stdc++.h>

using namespace std;

int n, t;
char cube[6][3][3];
char temp[3][3];

void rotate(int side, bool dir) {
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			if(dir) temp[3-j-1][i] = cube[side][i][j]; 	//반시계 
			else temp[j][3-i-1] = cube[side][i][j];		//시계 
		}
	}
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			cube[side][i][j] = temp[i][j];
		}
	}
}

void swap(int c1, int c2, int i, int j) {
	char temp = cube[c2][i][j];
	cube[c2][i][j] = cube[c1][i][j];
	cube[c1][i][j] = temp;
}

void print() {
	for(int i=0; i<3; i++) {
		for(int j =0; j<3; j++) {
			cout << cube[0][i][j];
		}
		cout << "\n";
	}
}
void solve(int side, char dir) {
	if(dir == '-') {
		rotate(side, 1);
		if(side == 0) {
			swap(5, 2, 0, 0); swap(2, 4, 0, 0); swap(4, 3, 0, 0);
			swap(5, 2, 0, 1); swap(2, 4, 0, 1); swap(4, 3, 0, 1);
			swap(5, 2, 0, 2); swap(2, 4, 0, 2); swap(4, 3, 0, 2);
		}
		if(side == 1) {
			swap(5, 2, 2, 0); swap(5, 3, 2, 0); swap(4, 3, 2, 0);
			swap(5, 2, 2, 1); swap(5, 3, 2, 1); swap(4, 3, 2, 1);
			swap(5, 2, 2, 2); swap(5, 3, 2, 2); swap(4, 3, 2, 2);
		}
		if(side == 2) {
			swap(4, 0, 2, 0); swap(0, 5, 2, 0); swap(5, 1, 2, 0);
			swap(4, 0, 2, 1); swap(0, 5, 2, 1); swap(5, 1, 2, 1);
			swap(4, 0, 2, 2); swap(0, 5, 2, 2); swap(5, 1, 2, 2);
		}
		if(side == 3) {
			swap(5, 0, 0, 0); swap(0, 4, 0, 0); swap(4, 1, 0, 0);
			swap(5, 0, 0, 1); swap(0, 4, 0, 1); swap(4, 1, 0, 1);
			swap(5, 0, 0, 2); swap(0, 4, 0, 2); swap(4, 1, 0, 2);
		}
		if(side == 4) {
			swap(0, 2, 0, 0); swap(2, 1, 0, 0); swap(1, 3, 0, 0);
			swap(0, 2, 1, 0); swap(2, 1, 1, 0); swap(1, 3, 1, 0);
			swap(0, 2, 2, 0); swap(2, 1, 2, 0); swap(1, 3, 2, 0);
		}
		if(side == 5){
			swap(0, 2, 0, 2); swap(0, 3, 0, 2); swap(1, 3, 0, 2);
			swap(0, 2, 1, 2); swap(0, 3, 1, 2); swap(1, 3, 1, 2);
			swap(0, 2, 2, 2); swap(0, 3, 2, 2); swap(1, 3, 2, 2);
		}
	}
	else {
		rotate(side, 0);
		if(side == 0) {
			swap(5, 2, 0, 0); swap(5, 3, 0, 0); swap(4, 3, 0, 0);
			swap(5, 2, 0, 1); swap(5, 3, 0, 1); swap(4, 3, 0, 1);
			swap(5, 2, 0, 2); swap(5, 3, 0, 2); swap(4, 3, 0, 2);
		}
		if(side == 1) {
			swap(5, 2, 2, 0); swap(2, 4, 2, 0); swap(4, 3, 2, 0);
			swap(5, 2, 2, 1); swap(2, 4, 2, 1); swap(4, 3, 2, 1);
			swap(5, 2, 2, 2); swap(2, 4, 2, 2); swap(4, 3, 2, 2);
		}
		if(side == 2) {
			swap(4, 0, 2, 0); swap(4, 1, 2, 0); swap(5, 1, 2, 0);
			swap(4, 0, 2, 1); swap(4, 1, 2, 1); swap(5, 1, 2, 1);
			swap(4, 0, 2, 2); swap(4, 1, 2, 2); swap(5, 1, 2, 2);
		}
		if(side == 3) {
			swap(5, 0, 0, 0); swap(5, 1, 0, 0); swap(4, 1, 0, 0);
			swap(5, 0, 0, 1); swap(5, 1, 0, 1); swap(4, 1, 0, 1);
			swap(5, 0, 0, 2); swap(5, 1, 0, 2); swap(4, 1, 0, 2);
		}
		if(side == 4) {
			swap(0, 2, 0, 0); swap(0, 3, 0, 0); swap(1, 3, 0, 0);
			swap(0, 2, 1, 0); swap(0, 3, 1, 0); swap(1, 3, 1, 0);
			swap(0, 2, 2, 0); swap(0, 3, 2, 0); swap(1, 3, 2, 0);
		}
		if(side == 5){
			swap(0, 2, 0, 2); swap(2, 1, 0, 2); swap(1, 3, 0, 2);
			swap(0, 2, 1, 2); swap(2, 1, 1, 2); swap(1, 3, 1, 2);
			swap(0, 2, 2, 2); swap(2, 1, 2, 2); swap(1, 3, 2, 2);
		}
	}
}

int chk(char &c) {
	if(c == 'U') return 0;
	if(c == 'D') return 1;
	if(c == 'F') return 2;
	if(c == 'B') return 3;
	if(c == 'L') return 4;
	return 5;
}

void input() {
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			cube[0][i][j] = 'w';
			cube[1][i][j] = 'y';
			cube[2][i][j] = 'r';
			cube[3][i][j] = 'o';
			cube[4][i][j] = 'g';
			cube[5][i][j] = 'b';
		}
	}	
	string s;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> s;
		solve(chk(s[0]), s[1]);
	}
	for(int i = 0; i<3; i++) {
		for(int j= 0; j<3; j++) {
			cout << cube[2][i][j];
		}
		cout << "\n";
	}
	for(int i = 0; i<3; i++) {
		for(int j= 0; j<3; j++) {
			cout << cube[2][i][j];
		}
		cout << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		input();	
	}
	
	return 0;
}

// 옆면 바뀌는 걸 제대로 못함 05:07 
