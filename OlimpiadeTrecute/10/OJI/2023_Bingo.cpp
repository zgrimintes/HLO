///REZOLVARE DE 81 DE PUNCTE
#include <fstream>
#include <iostream>
#include <cstring>

#define NMAX 1000000001

using namespace std;

ifstream fin("bingo.in");
ofstream fout("bingo.out");

int ras[100001];
char sir[100001], toCheck[5] = { 'b', 'i', 'n', 'g', 'o' };
pair <bool, char> lett[5];
int pos[5];
int T, ind_ras;
int cnt_swaps, opt_swaps = NMAX;

void findClosestLetters(int i) {
	int cnt_lit = 0;
	for (int j = 1; cnt_lit < 2; j++) {
		if (i - j < 0) break;

		int let_ind = strchr(toCheck, sir[i - j]) - toCheck;

		if (strchr(toCheck, sir[i - j]) && lett[let_ind].first == false) {
			lett[let_ind].first = true;
			lett[2 - ++cnt_lit].second = sir[i - j];
			pos[2 - cnt_lit] = i - j;
		}
	}

	cnt_lit = 0;
	for (int j = 1; cnt_lit < 2; j++) {
		if (!sir[i + j]) break;

		int let_ind = strchr(toCheck, sir[i + j]) - toCheck;

		if (strchr(toCheck, sir[i + j]) && lett[let_ind].first == false) {
			lett[let_ind].first = true;
			lett[2 + ++cnt_lit].second = sir[i + j];
			pos[2 + cnt_lit] = i + j;
		}
	}
}

bool checkFound() {
	for (int i = 0; i < 5; i++)
		if (!lett[i].first) return false;

	return true;
}

void resetLetters() {
	for (int i = 0; i < 5; i++)
		lett[i].first = false, 
		lett[i].second = 0,
		pos[i] = 0;
}

void getAllClose() {
	pos[0] += 2;
	pos[1] += 1;
	pos[3] -= 1;
	pos[4] -= 2;

	cnt_swaps += abs(pos[2] - pos[0]);
	cnt_swaps += abs(pos[2] - pos[1]);
	cnt_swaps += abs(pos[2] - pos[3]);
	cnt_swaps += abs(pos[2] - pos[4]);
}

void getInversions() {
	int S[5];

	for (int i = 0; i < 5; i++) {
		S[i] = strchr(toCheck, lett[i].second) - toCheck;
	}

	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++) 
			if (S[i] > S[j]) cnt_swaps++;
}

void getLuckyNb() {
	if (strstr(sir, "bingo")) {
		ras[ind_ras++] = 0;
		return;
	}

	for (int i = 2; sir[i + 2]; i++) {
		if (!strchr(toCheck, sir[i])) continue;

		lett[strchr(toCheck, sir[i]) - toCheck].first = true;
		lett[2].second = sir[i];
		pos[2] = i;

		findClosestLetters(i);

		if (checkFound()) {
			getAllClose();
			getInversions();

			if (cnt_swaps < opt_swaps)
				opt_swaps = cnt_swaps;
		}

		cnt_swaps = 0;
		resetLetters();
	}

	ras[ind_ras++] = opt_swaps;
	opt_swaps = NMAX;
}

void afisare() {
	for (int i = 0; i < ind_ras; i++)
		fout << ras[i] << "\n";
}

void solve() {
	while (T) {
		fin >> sir;
		getLuckyNb();
		T--;
	}

	afisare();
}

int main() {
	fin >> T;
	solve();

	return 0;
}

///REZOLVARE DE 78 DE PUNCTE
#include <fstream>
#include <limits.h>
#include <cstring>

#define NMAX LLONG_MAX

using namespace std;

ifstream fin("bingo.in");
ofstream fout("bingo.out");

int ras[100001];
char sir[100001], toCheck[5] = { 'b', 'i', 'n', 'g', 'o' };
pair <bool, char> lett[5];
int pos[5];
int T, ind_ras;
long long cnt_swaps, opt_swaps = NMAX;

void findClosestLetters(int i) {
	int cnt_lit_s = 0, cnt_lit_d = 0;
	int lg = strlen(sir);

	for (int j = 1; cnt_lit_s < 2 || cnt_lit_d < 2; j++) {
		if (((i - j < 0) && (i + j >= lg))) break;

		if (i - j >= 0) {
			int let_ind = strchr(toCheck, sir[i - j]) - toCheck;

			if (strchr(toCheck, sir[i - j]) && lett[let_ind].first == false && cnt_lit_s < 2) {
				lett[let_ind].first = true;
				lett[2 - ++cnt_lit_s].second = sir[i - j];
				pos[2 - cnt_lit_s] = i - j;
			}
		}

		if (i + j < lg) {
			int let_ind = strchr(toCheck, sir[i + j]) - toCheck;

			if (strchr(toCheck, sir[i + j]) && lett[let_ind].first == false && cnt_lit_d < 2 ) {
				lett[let_ind].first = true;
				lett[2 + ++cnt_lit_d].second = sir[i + j];
				pos[2 + cnt_lit_d] = i + j;
			}
		}
	}
}

bool checkFound() {
	for (int i = 0; i < 5; i++)
		if (!lett[i].first) return false;

	return true;
}

void resetLetters() {
	for (int i = 0; i < 5; i++)
		lett[i].first = false, 
		lett[i].second = 0,
		pos[i] = 0;
}

void getAllClose() {
	pos[0] += 2;
	pos[1] += 1;
	pos[3] -= 1;
	pos[4] -= 2;

	cnt_swaps += abs(pos[2] - pos[0]);
	cnt_swaps += abs(pos[2] - pos[1]);
	cnt_swaps += abs(pos[2] - pos[3]);
	cnt_swaps += abs(pos[2] - pos[4]);
}

void getInversions() {
	int S[5];

	for (int i = 0; i < 5; i++) {
		S[i] = strchr(toCheck, lett[i].second) - toCheck;
	}

	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++) 
			if (S[i] > S[j]) cnt_swaps++;
}

void getLuckyNb() {
	for (int i = 2; sir[i + 2]; i++) {
		if (!strchr(toCheck, sir[i])) continue;

		lett[strchr(toCheck, sir[i]) - toCheck].first = true;
		lett[2].second = sir[i];
		pos[2] = i;

		findClosestLetters(i);

		if (checkFound()) {
			getAllClose();
			getInversions();

			if (cnt_swaps < opt_swaps)
				opt_swaps = cnt_swaps;
		}

		cnt_swaps = 0;
		resetLetters();
	}

	ras[ind_ras++] = opt_swaps;
	opt_swaps = NMAX;
}

void afisare() {
	for (int i = 0; i < ind_ras; i++)
		fout << ras[i] << "\n";
}

void solve() {
	while (T) {
		fin >> sir;
		getLuckyNb();
		T--;
	}

	afisare();
}

int main() {
	fin >> T;
	solve();

	return 0;
}
