#include <iostream>
#include <fstream>

#define LL long long

using namespace std;

ifstream fin("suman.in");
ofstream fout("suman.out");

LL gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	LL ans = 0, s = 0;

	int n, k; fin >> n >> k;
	int arr[25]; 
	for (int i = 0; i < k; i++) fin >> arr[i];
	LL b = 1 << k;

	for (int bm = 0; bm < b; bm++) {

		LL lcm = 0;
		int cnt_nr = 0;

		for (int i = 0; i < k; i++) {
			if ((1 << i) & bm) {
				cnt_nr++;

				if (!lcm) {
					lcm = arr[i];
				}
				else {
					lcm = (lcm * arr[i] * 1LL) / gcd(lcm, arr[i]);
				}

				if (lcm > n) break;
			}
		}

		if (lcm) {
			s = (lcm * (n / lcm + 1) * (n / lcm) * 1LL) / 2;

			if (cnt_nr % 2) ans += s;
			else ans -= s;
		}
	}

	fout << ans;

	return 0;
}
