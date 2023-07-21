//acmicpc 7662
//authored by jihwankim
//23-07-21 AM 03:42

#include <bits/stdc++.h>

using namespace std;

int k;
multiset<int> s;
char inst;
int num;

void insertion(int n) {
	s.insert(n);
} 

void deletion(int n) {	
	if(s.empty()) return;
	if(n == -1) {
		s.erase(s.begin());
	}
	else {
		auto it = s.end();
		s.erase(--it);
	}
}

void input() {
	cin >> k;
	for(int i = 0; i<k; i++) {
		cin >> inst >> num; 
		if(inst == 'I') {
			insertion(num);
		}
		else {
			deletion(num);
		}
	}	
}

void print() {
	if(s.empty()) cout << "EMPTY\n";
	else {
		auto minIt = s.begin();
		auto maxIt = s.end();
		cout << *(--maxIt) << " " << *minIt << "\n";
	}
}

void clear() {
	while(!s.empty()) {
		s.erase(*s.begin());
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--) {
		input();
		print();
		clear();
	}
	
	return 0;
}
//AM 03:59
