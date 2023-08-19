// acmicpc 1021
// authored by jihwankim
// study
// 23-08-20 AM 01:46
#include <bits/stdc++.h>

using namespace std;

int n, m;
deque<int> dq;
int cnt;

void solve(int key) {
	int leftCnt = 0;
	int rightCnt = 0;
	
	deque<int> leftDq = dq;
	deque<int> rightDq = dq;
	
	while(leftDq.front() != key) {
		leftDq.push_back(leftDq.front());
		leftDq.pop_front();
		leftCnt++;
	}
	while(rightDq.front() != key) {
		rightDq.push_front(rightDq.back());
		rightDq.pop_back();
		rightCnt++;
	}
	
	
	if(leftCnt <= rightCnt) {
		leftDq.pop_front();
		dq = leftDq;
		cnt += leftCnt;
	}
	else {
		rightDq.pop_front();
		dq = rightDq;
		cnt += rightCnt;
	}
}

void input() {
	cin >> n >> m;
	for(int i = 1; i<=n; i++) dq.push_back(i);
	for(int i = 0; i<m; i++) {
		int num;
		cin >> num;
		solve(num);
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	
	return 0;
}
// AM 02:11
