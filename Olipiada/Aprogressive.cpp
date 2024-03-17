//C1, C2
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("aprogressive.in");
ofstream fout("aprogressive.out");

int c, n, m;
int mat[1025][1025];
int ans1[1025], ans2[1025];
int i_ans1, i_ans2;
int sumeS[1025][1025];

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

int main() {
	fin >> c >> n >> m;
	citire();

	switch (c)
	{
	case 1: afisare(ans1, i_ans1); break;
	case 2: afisare(ans2, i_ans2); break;
	default:
		break;
	}
	return 0;
}
