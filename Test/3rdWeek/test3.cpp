// PM 06 : 32
#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, pair<string, int> > > v;

// 나이별 내림차순, 입력받은 순서 내림차순. 
bool cmp(pair<int, pair<string, int> > &p1, pair<int, pair<string, int> > &p2) {
	if(p1.first == p2.first) {
		return p1.second.second < p2.second.second;
	}
	return p1.first < p2.first;
}

void input() {
	cin >> n;
	int age;
	string name;
	for(int i = 0; i<n; i++) {
		cin >> age >> name;
		v.push_back({age, {name, i}});
	}
	
	sort(v.begin(), v.end(), cmp);
}
int main() {
	input();
	for(int i = 0; i<n; i++) {
		cout << v[i].first << " " << v[i].second.first << "\n";
	}
	return 0;
}

// PM 06 :37
