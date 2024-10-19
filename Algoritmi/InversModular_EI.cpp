#include <fstream> 

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

int MOD;
int a, n;

int gcdExtended(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;

	return gcd;
}


void inverse_mod() {
	int x, y;
	int g = gcdExtended(a, n, x, y);


	if (x < 0) x = (x % MOD + MOD) % MOD;

	fout << x;
}

int main() {

	fin >> a >> n;
	MOD = n;
	inverse_mod();

	return 0;
}
