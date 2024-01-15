//REZOLVARE DE 70 DE PUNCTE
#include <iostream>

#define MOD 1000000007

long long factmod(int n) {
	long long rez = 1;

	for (int i = 2; i <= n; i++)
		rez = rez * i % MOD;

	return rez % MOD;
}

void solve(int n) {
	long long sum = 0;
	long long prev_fact = 1;

	sum = (n + 1) % MOD * factmod(n + 1) - 1;

	/*for (int i = 1; i <= n; i++) {
		prev_fact = (prev_fact * i) % MOD;
		sum += (prev_fact * (i * i + i + 1) % MOD);
	}*/

	std::cout << sum % MOD;
}

int main() {
	int n;
	std::cin >> n;
	solve(n);

	return 0;
}
