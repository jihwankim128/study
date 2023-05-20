// acmicpc.net/problem/10808
// author : kimjihwan
// 2023-05-20 PM 1:30

#include <iostream>
#include <string> 

using namespace std;

int arr[26];
string s;

void solve() {
	cin >> s;
	for(int i = 0; i<s.size(); i++) arr[s[i]-'a']++;
	for(int i = 0; i<26; i++) cout << arr[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}

// 2023-05-20 PM 1:30
