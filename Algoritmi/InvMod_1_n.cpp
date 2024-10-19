#include <iostream>

using namespace std;

int n, MOD;

int gcdExtended(int a, int b, int &k, int &l) {
	if (!b) {
		k = 1;
		l = 0;
		return a;
	}

	int k1, l1;

	int gcd = gcdExtended(b, a % b, k1, l1);

	k = l1;
	l = k1 - (l1 * (a / b));

	return gcd;
}

int modInverse(int i) {
	int x, y;
	int gcd = gcdExtended(i, MOD, x, y);

	if (x < 0) return (x % MOD + MOD) % MOD;

	return x;
}

int main() {
	cin >> n >> MOD;

	for (int i = 1; i <= n; i++) {
		cout << modInverse(i) << " ";
	}

	return 0;
}

///SAU UN APPROACH DINAMIC

/*
#include <iostream>

using namespace std;

int n, MOD;

void modularInverse() {
	int dp[1001];
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[MOD % i] * (MOD - MOD / i) % MOD;
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
}

int main() {
	cin >> n >> MOD;
	modularInverse();
	return 0;
}
*/
