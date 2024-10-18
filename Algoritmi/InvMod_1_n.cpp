/*
#include <iostream>

using namespace std;

int n, MOD;

int modInverse(int i) {
	
}

int main() {
	cin >> n >> MOD;

	for (int i = 1; i <= n; i++) {
		cout << modInverse(i) << " ";
	}

	return 0;
}
*/

///SAU UN APPROACH DINAMIC

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
