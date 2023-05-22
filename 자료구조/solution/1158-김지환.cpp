// acmicpc.net/problem/1158
// ¿¡µðÅÍ 
// author : kimjihwan
// 2023-05-22 PM 04:11 

#include <iostream>
#include <string> 
#include <list>

using namespace std;

int n, k;
list<int> josephus; 

void input() {
	cin >> n >> k;
	for(int i = 1; i<=n; i++)
		josephus.push_back(i);
}

void solve() {
	list<int>::iterator v;
	v = josephus.end();
	
	cout << "<";
	
	for(int j = 0; j<k; j++) {
		v++; 
		if(v==josephus.end()) v++;
	}
	cout << *v;
	v = josephus.erase(v);
	v--;
	
	for(int i = 1; i<n; i++) {
		for(int j = 0; j<k; j++) {
			v++; 
			if(v==josephus.end()) v++;
		}
		cout << ", " << *v;
		v = josephus.erase(v);
		v--;
	}
	cout << ">";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}

// 2023-05-22 PM 04:29
