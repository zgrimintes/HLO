//C1, C2, C3
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("aprogressive.in");
ofstream fout("aprogressive.out");

const int nmax = 1030;

int c, n, m;
int mat[nmax][nmax];
int ans1[nmax], ans2[nmax];
int i_ans1, i_ans2;
int sumeS[nmax][nmax], sume[nmax];

int checkBar(int *s, int st, int fn) {
	sort(s + st, s + fn + 1);

	int r = s[st + 1] - s[st];

	for (int i = st + 2; i <= fn; i++)
		if (s[i] - s[i - 1] != r) return 0;

	return r;
}

void citire() {
	int max_sum = 0;
	int temp[1025];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			fin >> mat[i][j];
			sumeS[i][j] = sumeS[i][j - 1] + mat[i][j];
			temp[j] = mat[i][j];
		}
		if (checkBar(temp, 1, m)) ans2[i_ans2++] = i;

		if (max_sum < sumeS[i][m]) {
			max_sum = sumeS[i][m];
			i_ans1 = 0;
			ans1[i_ans1++] = i;
		}
		else if (max_sum == sumeS[i][m]) ans1[i_ans1++] = i;
	}
}

void afisare(int *s, int fn) {
	for (int i = 0; i < fn; i++)
		fout << s[i] << "\n";
}

void pushToAns(int x1, int x2, int y1, int y2, int r) {
	fout << "(";
	fout << x1 << "," <<
		y1 << "," <<
		x2 << "," <<
		y2 << "," << r;
	fout << ")";
}

void calcSums(int st, int fn, int l, int r) {
	for (int i = st; i <= fn; i++)
		sume[i] = sumeS[i][r] - sumeS[i][l - 1];
}

void solve3(int x1, int x2, int y1, int y2) {
	if (x1 == x2 || y1 == y2) {
		pushToAns(x1, x2, y1, y2, 0);
		return;
	}

	calcSums(x1, x2, y1, y2);

	int r = checkBar(sume, x1, x2);
	if (r) pushToAns(x1, x2, y1, y2, r);
	else {
		int n_x2 = (x1 + x2) / 2, n_y2 = (y2 + y1) / 2;
		fout << "(";
		solve3(x1, n_x2, y1, n_y2);
		solve3(x1, n_x2, n_y2 + 1, y2);
		solve3(n_x2 + 1, x2, y1, n_y2);
		solve3(n_x2 + 1, x2, n_y2 + 1, y2);
		fout << ")";
	}
}

int main() {
	fin >> c >> n >> m;
	citire();

	switch (c)
	{
	case 1: afisare(ans1, i_ans1); break;
	case 2: afisare(ans2, i_ans2); break;
	case 3:
		//fout << "(";
		solve3(1, n, 1, m);
		//fout << ")";
	default:
		break;
	}
	return 0;
}
