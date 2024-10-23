#include <iostream>

#define MOD 1000000007

using namespace std;

long long t, n, m;

long long facts[500001];
pair <long long, long long> arr[54];

long long powBin(long long a, long long n) {
	long long res = 1;

	while (n) {
		if (n % 2) res = (res * a) % MOD;

		a = (a * a) % MOD;
		n /= 2;
	}

	return res % MOD;
}

void get_facts() {
	facts[0] = 1;
	facts[1] = 1;
	for (int i = 2; i <= 500000; i++) {
		facts[i] = i * facts[i - 1] % MOD;
	}
}

long long combs(long long n, long long k) {
	return ( facts[n] * 
			(powBin(facts[n - k], MOD - 2) % MOD) % MOD * 
			(powBin(facts[k], MOD - 2) % MOD) ) % MOD;
}

long long solve(int i) {

	m = arr[i].first;
	n = arr[i].second;

	long long ans = 0;

	for (int i = 0; i <= m - n; i++) {
		ans = (ans + combs(m - i - 1, n - 1) * powBin(n, i) % MOD * powBin(n - 1, m - n - i) % MOD) % MOD;
	}

	return ans;
}

int main() {
	cin >> t;

	get_facts();

	for (int i = 0; i < t; i++) cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < t; i++)
		cout << solve(i) << "\n";

	return 0;
}
