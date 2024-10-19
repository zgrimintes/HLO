#include <iostream>

#define MOD 1000000007

using namespace std;

long long dp[101][101];

int numMusicPlaylists(int n, int goal, int k) {

	dp[0][0] = 1;

	for (int i = 1; i <= goal; i++) {
		for (int j = 1; j <= min(i, n); j++) {

			dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD;

			if (j > k) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
			}
		}
	}

	return dp[goal][n] % MOD;
}

int main() {
	int n, goal, k;
	cin >> n >> goal >> k;

	cout << numMusicPlaylists(n, goal, k);

	return 0;
}
