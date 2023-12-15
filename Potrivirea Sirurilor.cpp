#include <iostream>
#include <fstream>
#include <cstring>

#define p 83
#define MOD1 %30000041
#define MOD2 %700129

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

char A[2000001], B[2000001];
int matches[2000001];
int hashA1, hashA2, p1 = 1, p2;
int cnt_match;

int main() {
	fin.getline(A, 2000001);
	fin.getline(B, 2000001);

	int nA = strlen(A);
	int nB = strlen(B);

	if (nA > nB) {
		fout << 0;
		return 0;
	}

	///Hash pentru sirul A
	for (int i = 0; i < nA; i++) {
		hashA1 = (hashA1 * p + A[i]) MOD1;
		hashA2 = (hashA2 * p + A[i]) MOD2;

		if (i != 0) {
			p1 = (p1 * p) MOD1;
			p2 = (p2 * p) MOD2;
		}
	}

	int hashB1 = 0, hashB2 = 0;

	///Hash pentru sirul B
	for (int i = 0; i < nA; i++) {
		hashB1 = (hashB1 * p + B[i]) MOD1;
		hashB2 = (hashB2 * p + B[i]) MOD2;
	}

	if (hashA1 == hashB1 && hashA2 == hashB2) {
		matches[0] = 1;
		cnt_match++;
	}

	for (int i = nA; i < nB; i++) {
		///Rolling Hash
		hashB1 = ((hashB1 - (B[i - nA] * p1)MOD1 + 30000041) * p + B[i]) MOD1;
		hashB2 = ((hashB2 - (B[i - nA] * p2)MOD2 + 700129) * p + B[i]) MOD2;

		if (hashA1 == hashB1 && hashA2 == hashB2) {
			matches[i - nA + 1] = 1;
			cnt_match++;
		}
	}

	fout << cnt_match; cnt_match = 0;
	for (int i = 0; i < nB && cnt_match < 1000; i++) {
		if (matches[i]) {
			fout << i;
			cnt_match++;
		}
	}

	return 0;
}
