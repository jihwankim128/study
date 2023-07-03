#include <stdio.h>
#define min(a, b) ((a < b) ? (a) : (b))

int dp2[1001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	k = min(n-k, k);
	
	dp2[0] = 1;
	for(int i = 0; i<=n; i++) {
		int prev = 1;
		for(int j = 1; j<=min(i, k); j++) {
			int temp = dp2[j];
			dp2[j] = (prev+dp2[j])%10007;
			prev = temp;
		}
	}
	
	printf("%d",dp2[k]);
		
	return 0;
}
