#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("castel1.in");
ofstream fout("castel1.out");

int castel[105][105];
int castel2[105][105];
int cnt_cam = 0;
int arie = 0, arie_max = 0;
int itemp = 0, jtemp = 0;
int is, js, ij, jj;

void citire(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			fin >> castel[i][j];
		}
}

void bordare(int n) {
	for (int i = 0; i <= n; i++)
		castel[i][0] = castel[i][n] = castel[0][i] = castel[n][i] = -1;

}

void fil(int i, int j) {
	arie++;
	itemp = max(i, itemp);
	jtemp = max(j, jtemp);
	castel2[i][j] = 1;

	if ((castel[i][j] & 1) == 0 && castel2[i][j - 1] == 0)
		fil(i, j - 1);
	if ((castel[i][j] & 2) == 0 && castel2[i+1][j] == 0)
		fil(i + 1, j);
	if ((castel[i][j] & 4) == 0 && castel2[i][j + 1] == 0)
		fil(i, j + 1);
	if ((castel[i][j] & 8) == 0 && castel2[i-1][j] == 0)
		fil(i - 1, j);

}

void cerinte(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (castel[i][j] == 9 || castel[i][j] == 11 || castel[i][j] == 13 || castel[i][j] == 15) {
				arie = itemp = jtemp = 0;
				cnt_cam++;
				fil(i, j);

				if (arie > arie_max) {
					arie_max = arie;
					is = i; ij = itemp;
					js = j; jj = jtemp;
				}
			}
		}
	}
}


int main() {
	int n, c;
	fin >> c >> n;
	citire(n);
	bordare(n + 1);
	cerinte(n);

	if (c == 1) fout << cnt_cam;
	if (c == 2) fout << arie_max;
	if (c == 3) fout << is << " " << js << " " << ij << " " << jj;

}
