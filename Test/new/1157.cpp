/*
	acmicpc 1157
	23-11-24 AM 10:59 ~ 11:06
*/
#include <string>
#include <iostream>
#include <vector>
#define max(a, b) ((a > b) ? (a) : (b))

using namespace std;

int arr[26];

int main() {
	string s;
	cin >> s;
	
	int cnt = 0;
	for(char &c : s) {
		arr[toupper(c)-'A']++;
		cnt = max(cnt, arr[toupper(c)-'A']);
	}
	
	vector<char> answer;
	for(int i = 0; i < 26; i++) {
		if(arr[i] == cnt) answer.push_back(i+'A');
	}
	
	if(answer.size() == 1) cout << answer[0];
	else cout << '?';
	
	return 0;
}
