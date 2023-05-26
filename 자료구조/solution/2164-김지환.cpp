// acmicpc.net/problem/2164
// Ä«µå2
// author : kimjihwan
// 2023-05-24 PM 04:44
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

queue<int> q;
int n;

void input() {
    cin >> n;
    for(int i = 1; i<=n; i++) q.push(i);
}

void solve() {
    while(q.size() > 1) {
        q.pop(); 
        q.push(q.front()); 
        q.pop();
    }
    cout << q.front();
}
int main() {
    fastio;
    input();
    solve();
	return 0;
}
// PM 04:47
