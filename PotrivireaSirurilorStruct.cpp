///REZOLVARE DE 100 DE PUNCTE, FOLOSIND STRUCTURI
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

char A[2000001], B[2000001];
int matches[2000001];
int cnt_match;

struct Hash
{
	/// n - putere initiala, m - MOD
	long long n, m, power, hashh;

	void init(char* s, int len) {
		power = 1;
		hashh = 0;

		for (int i = len - 1; i >= 0; i--) {
			hashh = (hashh + (power * s[i]) % m) % m;

			if (i) power = (power * n) % m;
		}
	}

	void roll(char toRemove, char toAdd) {
		hashh = ((hashh - (toRemove * power) % m + m) * n + toAdd) % m;
	}
};

int main()
{
	fin.getline(A, 2000001);
	fin.getline(B, 2000001);

	int nA = strlen(A);
	int nB = strlen(B);

	if (nA > nB) {
		fout << 0;
		return 0;
	}

	Hash a1Hash{ 83, 3000001 }, b1Hash{ 83, 3000001 };
	Hash a2Hash{ 53, 700021 }, b2Hash{ 53, 700021 };

	a1Hash.init(A, nA);
	a2Hash.init(A, nA);
	b1Hash.init(B, nA);
	b2Hash.init(B, nA);

	if (a1Hash.hashh == b1Hash.hashh && a2Hash.hashh == b2Hash.hashh) matches[cnt_match++] = 1;

	for (int i = nA; i < nB; i++) {
		b1Hash.roll(B[i - nA], B[i]);
		b2Hash.roll(B[i - nA], B[i]);

		if (a1Hash.hashh == b1Hash.hashh && a2Hash.hashh == b2Hash.hashh) {
			if (cnt_match <= 1000)
				matches[cnt_match++] = i - nA + 1;
			else
				cnt_match++;
		}
	}

	fout << cnt_match << "\n";

	if (cnt_match > 1000) cnt_match = 1000;

	for (int i = 0; i < cnt_match; i++)
		fout << matches[i] << " ";

	return 0;
}
