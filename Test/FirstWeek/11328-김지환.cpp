#include <iostream>
#include <string>

using namespace std;

int n;
int arr1[26];
int arr2[26];

void input() {
	string s1;
	string s2;
	cin >> s1 >> s2; 
	for(int i = 0; i<26; i++) {
		arr1[i] = 0;
		arr2[i] = 0;
	}
	for(int i = 0; i<s1.size(); i++) {
		arr1[s1[i]-'a']++;
		arr2[s2[i]-'a']++;
	}
}

bool solve() {
	for(int i = 0; i<26; i++) {
		if(arr1[i] != arr2[i]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--) {
		input();
		if(solve()) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	
	return 0;
} 
