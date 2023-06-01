#include <bits/stdc++.h>

using namespace std;

stack <int> nums;

int main() {
	int k;
	int num;
	int sum = 0;
	cin >> k;
	nums.push(0);
	for (int i = 0; i < k; i++) {
		cin >> num;
		
		if (num != 0) nums.push(num);
		else nums.pop();
	}
	while (!nums.empty()) {
		sum += nums.top();
		nums.pop();
	}
	cout << sum;
}