// acmicpc.net/problem/3015 
// 오아시스 재결합 
// author : kimjihwan
// 2023-05-22 PM 4:00 
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;

int n, k;
stack<pair<int, int> > st;

void solve() {
    cin >> n;
    ll cnt = 0;
    for(int i = 0; i<n; i++) {
        int shotter = 1;
        cin >> k;
        while(!st.empty() && st.top().first <= k) {
            cnt+=st.top().second;
            if(st.top().first == k) shotter+=st.top().second;
            st.pop();
        }
        if(!st.empty()) cnt++;
        st.push({k, shotter});
    }
    cout << cnt;
}

int main()
{
    fastio;
    solve();
    return 0;
}


//fail, retry 
