// acmicpc 10866
// authored by jihwankim
// study
// 23-08-20 AM 01:28
#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 20005;
int dq[MAX_SIZE];
int head = 10000;
int tail = 10000;
int n;

void solve(string op) {
	if(op == "push_back") {
		int data; 
		cin >> data;
		dq[++tail] = data;
	}
	else if(op == "push_front") {
		int data; 
		cin >> data;
		dq[head--] = data; 
	}
	else if(op == "front") {
		if(tail-head == 0) cout << "-1\n"; 
		else cout << dq[head+1] << "\n";	
	}
	else if(op == "back") {
		if(tail - head == 0) cout << "-1\n";
		else cout << dq[tail] << "\n";	
	}
	else if(op == "size") cout << tail-head << "\n";
	else if(op == "empty") cout << ((tail-head) == 0) << "\n";
	else if(op == "pop_front") {
		if(tail-head == 0) cout << "-1\n"; 
		else cout << dq[++head] << "\n";		
	}
	else {
		if(tail - head == 0) cout << "-1\n";
		else cout << dq[tail--] << "\n";	
	}
}
void input() {
	cin >> n;	
	for(int i = 0; i<n; i++) {
		string op;
		cin >> op;
		solve(op);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	
	return 0;
}
// AM 01:45
