// acmicpc.net/problem/1919
// 애너그램 만들 
// author : kimjihwan
// 2023-05-21 AM 05:35

#include <iostream>
#include <cmath>

using namespace std;

string s1, s2;
int arr1[26];
int arr2[26];

void input() {
	cin >> s1 >> s2;
}

void solve() {
	for(int i = 0; i<s1.size(); i++) arr1[s1[i]-'a']++;
	for(int i=0; i<s2.size(); i++) arr2[s2[i]-'a']++;
	
	int cnt = 0;
	for(int i = 0; i<26; i++) cnt += abs(arr1[i]-arr2[i]);
	
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-21 AM 05:42
