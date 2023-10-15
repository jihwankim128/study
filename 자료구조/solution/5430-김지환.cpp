// acmicpc 5430
// authored by jihwankim
// study
// 23-08-20 AM 02:12
#include <bits/stdc++.h>

using namespace std;

string op;
int n;
deque<int> dq;
string nums;

void solve() {
	bool reversed = false;
	for(char &x : op) {
		if(x == 'R') reversed = reversed ? false : true;
		else {
			if(dq.size() == 0) {
				cout << "error\n";
				return ;
			}
			if(reversed) dq.pop_back();				
			else dq.pop_front();
		}
	}
	
	if(reversed) {
		cout << "[";
		for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
		    cout << *it;
		    if (it != dq.rend() - 1) cout << ",";
		}
		cout << "]\n";
	}
	else {
		cout << "[";
		for (auto it = dq.begin(); it != dq.end(); ++it) {
		    cout << *it;
		    if (it != dq.end() - 1) cout << ",";
		}
		cout << "]\n";
	}
}

void input() {
	dq.clear();
	cin >> op >> n >> nums;
	for(int i = 1; i<nums.size(); i++) {
		string num;
		while(nums[i] != ',' && nums[i] != ']') num += nums[i++];
		if(!num.empty()) dq.push_back(stoi(num));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--) {	
		input();
		solve();
	}
	
	return 0;
}
// AM 02:50
