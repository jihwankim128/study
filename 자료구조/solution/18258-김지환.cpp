// acmicpc.net/problem/18258
// ť2
// author : kimjihwan
// 2023-05-24 PM 04:40
#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int n;
string inst;

void solve() {
	if (q.empty() && (inst == "pop" || inst == "front" || inst == "back")) {
		cout << "-1\n";
		return;	
	}
	if(inst == "pop") {
		cout << q.front() << "\n";
		q.pop();
	}
	else if(inst == "size") cout << q.size() << "\n";
	else if(inst == "empty") cout << q.empty() << "\n";
	else if(inst == "front") cout << q.front() << "\n";
	else cout << q.back() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	
	while(n--){
		cin >> inst;
		int num = 0;
		if(inst == "push") {
			cin >> num;
			q.push(num);
		}
		else solve();
	}
	return 0;
}
// PM 04:42
