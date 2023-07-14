#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int n, k;

void input() {
	cin >> n >> k;
	for(int i = 0; i<n; i++) 
		cin >> arr[i];
}

void solve() {
	
	int left = 0, right = 0;
	int length = 0, cnt = 0;
	int max_len = 0;
	
	for(left, right; right<n; right++) {
		if(arr[right] % 2) {
			//홀수일 경우
			//홀수제거 개수가 k와 같다면 다음 홀수부터의 길이 
			while(cnt == k) {
				if(arr[left++]%2) cnt--;
				else length--;
			}
			cnt++;
		}
		else {
			//짝수일 경우 
			length++;
		}
		max_len = max(max_len, length);
	}
	
	cout << max_len;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
		
	return 0;
}
