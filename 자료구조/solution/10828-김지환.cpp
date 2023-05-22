// acmicpc.net/problem/10828
// Ω∫≈√ 
// author : kimjihwan
// 2023-05-22 PM 04:36

#include <iostream>
#include <stack>
#include <string> 

using namespace std;

int n;
stack<int> st;

void push() {
	int num;
	cin >> num;
	st.push(num);
}

void top() {
	if(st.empty()) cout << "-1\n";
	else cout << st.top() << "\n";
}

void pop() {
	if(st.empty()) cout << "-1\n";
	else {
		cout << st.top() << "\n";
		st.pop();
	}
}

void solve() {
	string s;
	cin >> s;
	if(s=="push") push();
	else if(s=="top") top();
	else if(s=="size") cout << st.size() << "\n";
	else if(s=="empty") cout << st.empty() << "\n";
	else pop();
}

void input() {
	cin >> n;
	while(--n) {
		solve();
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}

// 2023-05-22 PM 04:45
