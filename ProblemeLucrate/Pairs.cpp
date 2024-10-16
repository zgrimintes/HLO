///REZ 20 PUNCTE
#include <fstream>
#include <set>

using namespace std;

ifstream fin("pairs.in");
ofstream fout("pairs.out");

set<int> arr;
int temp[100000];
int ans = 0;

void citire(int n) {
	for (int i = 0; i < n; i++) {
		int x; fin >> x;
		arr.insert(x);
	}
}

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

void solve(int n) {
	int id = 0;

	for (auto i : arr) temp[id++] = i;

	for (int i = 0; i < id - 1; i++) {
		for (int j = i + 1; j < id; j++) {
			if (gcd(temp[i], temp[j]) == 1) ans++;
		}
	}
}

int main() {
	int m; 
	fin >> m;
	citire(m);

	solve(m);

	fout << ans;

	return 0;
}


///IDK MAN
#include <fstream>
#include <set>
#include <vector>

using namespace std;

ifstream fin("pairs.in");
ofstream fout("pairs.out");

int ans = 0;
set <int> arr;
int x[100000];
int MAX = 0;
vector<int> primes;
vector<int> P;

void citire(int n) {
	for (int i = 0; i < n; i++) {
		int nr;
		fin >> nr; if (MAX < nr) MAX = nr;
		arr.insert(nr);
	}
}

void generate_P(int curr_prod, int idx) {
	if (curr_prod > 1 && curr_prod <= MAX)
		P.push_back(curr_prod);

	for (int i = idx; i < primes.size(); i++) {
		if (curr_prod * primes[i] > MAX) break;
		generate_P(curr_prod * primes[i], i + 1);
	}
}

int get_prod(int p) {
	int d = 1;
	int cnt = 0;
	while (p > 1)
	{
		if (p % d == 0) cnt++, p /= d;
		
		d++;
	}

	return cnt;
}

void ciur() {
	vector<bool> is_prime(MAX + 1, true);
	is_prime[0] = is_prime[1] = false; 
	for (int i = 2; i * i <= MAX; ++i) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= MAX; ++i) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}

}

void solve() {
	for (int i = 1; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			if (arr.find(j) != arr.end()) {
				x[i] = x[i] + 1;
			}
		}
	}

	ciur();

	generate_P(1, 0);

	for (auto p : P) {
		if (get_prod(p) % 2 == 0) ans -= x[p] * (x[p] - 1) / 2;
		else ans += x[p] * (x[p] - 1) / 2;
	}
}

int main() {
	int n; fin >> n;
	citire(n);
	
	ans = n * (n - 1) / 2;

	solve();

	fout << ans;

	return 0;
}
