///REZOLVARE DE 24 DE PUNCTE - C1
#include <fstream>
#include <cstring>

#define MOD 666013

using namespace std;

ifstream fin("circular.in");
ofstream fout("circular.out");

int c, t_min;
char a[50001];
char r[26];

void solve1() {
	char l = 'A';
	for (int i = 0; a[i]; i++) {
		t_min += min(abs(l - a[i]), 26 - abs(l - a[i]));
		l = a[i];
	}
}

int main() {
	fin >> c;
	fin.get();
	fin.getline(a, 50001);
	fin.getline(r, 26);

	if (c == 1) {
		solve1();
		fout << t_min;
	}
	else {

	}

	return 0;
}
