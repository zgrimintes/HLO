#include <iostream>

#define MOD 1000000007

using namespace std;

typedef long long LL;

int n, k;

LL powBin(LL a, LL n) {
	LL res = 1;

	while (n) { 
		if (n % 2) res = res * a % MOD;

		a = a * a % MOD;
		n /= 2;
	}

	return res;
}

LL solve() {
	LL ans = 0;

	for (int i = 1; i <= n; i++) {
		ans = ( ans + powBin(i, k) ) % MOD;
	}

	return ans;
}

int main() {
	cin >> n >> k;

	cout << solve();

	return 0;
}
