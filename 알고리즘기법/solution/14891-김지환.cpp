// acmicpc 14891
// authored by jihwankim
// study
// 23-10-10 PM 03:58
#include <bits/stdc++.h>

using namespace std;

deque<bool> arr[4];
vector<pair<int, int>> rotates;
int n;

void input() {
	// 방향을 모두 1과 0으로 저장 
	for(int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for(char &c : s) {
			if(c == '0') arr[i].push_back(false);
			else arr[i].push_back(true);
		}
	}
	
	cin >> n;
	// 회전하는 key 값과, 회전하는 방향 value를 저장 
	for(int i = 0; i <n; i++) {
		int a, b;
		cin >> a >> b;
		rotates.push_back({a-1, b});
	}
}

// 회전하는 메서드 
void rotation(int x, int dir, int prev) {
	// 회전하기 이전의 톱니 바퀴의 왼쪽, 오른쪽을 저장 
	// 0(top) ~ 7 이니까 6번과 2번이 값을 가짐. 
	// 맞물리는 방향 회전을 위해서 
	bool prev_left_status = arr[x][6];
	bool prev_right_status = arr[x][2];
		
	// 왼쪽일 경우 왼쪽 바퀴의 오른쪽과 비교 
	// 오른쪽일 경우 오른쪽 바퀴의 왼쪽과 비교 
	int left = x-1;
	int right = x+1;

	// 반시계 방향이면 top을 꼬리에 붙임.
	// 시계 방향이면 꼬리를 top에 붙임. 
	if(dir == -1) {
		arr[x].push_back(arr[x].front());
		arr[x].pop_front();
	}
	else {
		arr[x].push_front(arr[x].back());
		arr[x].pop_back();
	}	
	
	// valid(왼쪽, 오른쪽, 이전값 비교) 
	// 다른 극일 경우 회전 
	if(left >= 0 && left < 4 && prev != left) {	
		bool left_status = arr[left][2];
		if(prev_left_status != left_status) {
			rotation(left, (dir==1 ? -1 : 1), x);
		}
	}
	if(right >= 0 && right < 4 && prev != right) {	
		bool right_status = arr[right][6];
		if(prev_right_status != right_status) {
			rotation(right, (dir==1 ? -1 : 1), x);	
		}
	}
}

int solve() {
	for(int i = 0; i < n; i++) {
		int x = rotates[i].first;
		int dir = rotates[i].second;
		
		rotation(x, dir, -1);
	}
	
	int sum = 0;
	
	for(int i = 0; i < 4; i++) {
		sum += (arr[i].front() << i);
	}
	
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	cout << solve();
	
	return 0;
}
// PM 05:00
