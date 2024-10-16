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
