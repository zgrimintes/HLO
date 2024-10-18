#include <fstream>

#define LL long long

using namespace std;

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

void euclid_extins(LL a, LL b, LL& k, LL& l, LL& d) {
	if (!b) {
		k = 1;
		l = 0;
		d = a;

		return;
	}

	LL k1, l1;
	euclid_extins(b, a % b, k1, l1, d);
	k = l1;
	l = k1 - (l1 * (a / b));
}

int main() {
	int n;
	fin >> n;

	while (n) {
		LL cc;
		LL a, b, c; fin >> a >> b >> c; cc = c;
		LL k, l;

		euclid_extins(a, b, k, l, c);

		if (cc % c) fout << "0 0\n";
		else fout << k * (cc / c) << " " << l * (cc / c) << "\n";

		n--;
	}

	return 0;
}
