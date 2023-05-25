// acmicpc.net/problem/11003 
// 최솟값 찾기 
// author : kimjihwan
// 2023-05-25 AM 11:21 
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, k;
deque<int> dq;
priority_queue<int> pq;

void input() {
	cin >> n >> k;
	for(int i = 0; i<n; i++) {
		int num;
		cin >> num;
		dq.push_back(num);
		pq.push(-num);
	}
}

void solve() {
	for(int i = 0; i<k; i++) cout << -pq.top() << " ";
	pq.pop();
	for(int i = k; i<n; i++) {
		if(-pq.top() == dq[i-k]) {
			pq.pop();
		}
		cout << -pq.top() << " ";
	}
}

int main()
{
    fastio;
    input(); 
    solve();
    return 0;
}
//1. 무식하게 풀기 11:27 

//fail, retry 
