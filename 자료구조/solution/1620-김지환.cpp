//acmicpc 1620
//authored by jihwankim
//23-07-22 AM 11:28
#include <bits/stdc++.h>

using namespace std;

//HashMap
int n, m;

unordered_map<string, int> p_name;
unordered_map<string, string> p_num;

void input() {
	cin >> n >> m;
	for(int i = 1; i<=n; i++) {
		string name;
		cin >> name;
		p_name[name] = i;
		p_num[to_string(i)] = name;
	}
}

void solve() {
	string str;
	for(int i = 0; i<m; i++) {
		cin >> str;
		if(p_name.find(str) != p_name.end()) {
			cout << p_name[str] << "\n";
		}
		else {
			cout << p_num[str] << "\n";
		}
	}
}


/* lower_bound
int n, m;
pair<string, int> pocket_name[100005];
pair<int, string> pocket_num[100005];

void input() {
	cin >> n >> m;
	string name;
	for(int i = 1; i<=n; i++) {
		cin >> name;
		pocket_name[i] = {name, i};
		pocket_num[i] = {i, name};
	}
	sort(pocket_name, pocket_name+n+1);
}

int find_num(string key) {
	int s = 1;
	int e = n;
	int findIdx = e;
	while(s<=e) {
		int mid = (s+e)/2;
		if(pocket_name[mid].first >= key) {
			findIdx = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
	return pocket_name[findIdx].second;
}

void solve() {
	for(int i = 0; i<m; i++) {
		string str;
		cin >> str;
		int num;
		try {
			num = stoi(str);
			cout << pocket_num[num].second << "\n";
		}
		catch(exception) {
			cout << find_num(str) << "\n";
		}
	}
	
}*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	//freopen("input.txt","r",stdin);
	input();
	solve();
	
	return 0;
}
//AM 11:59
