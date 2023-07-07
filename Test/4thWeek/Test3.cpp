//4th test
//23-07-07 PM 06:40
//authored by jihwankim

#include <bits/stdc++.h>

using namespace std;

int arr[100001];
string n;

bool cmp(char &c1, char &c2) {
	return c1 > c2;
}

void solve() {
	int pointer = 0;
	string s = n;
	while(pointer < n.size()) {
		int num = n[pointer];
		if(pointer != 0) {
			int prev = n[pointer-1]-'0';
			n[pointer-1] = '0';
			num += prev;
		}	
		num %= 3;
		n[pointer] = num + '0';
		pointer++;
	} 
	if(n[pointer-1] == '0') cout << s;
	else cout << -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n;
	sort(n.begin(), n.end(), cmp);
	solve();
	
	return 0;
}

/*
30, 60, 90, 120, 150, 180, 210, 240, 270
앞에서부터 3씩 짤라보기
3보다 작으면 ? 다음 
*/

