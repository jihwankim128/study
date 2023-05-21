// acmicpc.net/problem/5397
// Å°·Î°Å 
// author : kimjihwan
// 2023-05-22 AM 02:38

#include <iostream>
#include <string> 
#include <list>

using namespace std;

int n; 
string s;

void solve() {
	list<char> cList;
	list<char>::iterator l;
	
	for(int i = 0; i<s.size(); i++) {
		char c = s[i];
		
		if(cList.empty()) {
			if(c=='<' || c=='>' || c=='-') continue;
			cList.push_back(c);
			l = cList.end();
			continue;
		}
		
		if(c == '-') {
			if(l != cList.begin()) {
				l--;
				l = cList.erase(l);
			}
		}
		else if(c == '>') {
			if(l!=cList.end()) l++;
			continue;	
		}
		else if(c == '<') {
			if(l!=cList.begin()) l--;
			continue;	
		}
		else cList.insert(l, c);
 	}
 	
 	for(l = cList.begin(); l != cList.end(); l++) {
 		cout << *l << "";
	}
	cout << "\n";
}

void input() {
	cin >> n;
	while(n--) {
		cin >> s;
		solve();
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	
	return 0;
}
// 2023-05-21 AM 03 : 35
