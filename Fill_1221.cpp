//REZOLVARE DE 20 DE PUNCTE
#include <iostream>

using namespace std;

char mat[1005][1005];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int cnt_poz = 0;
void fillV(int i, int j);

void citire(int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mat[i][j];
}	


void fil(int i, int j) {
	if (mat[i][j] != '.') return;
	cnt_poz = 0;
	
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k],
			nj = j + dj[k];
		if (mat[ni][nj] == '.') cnt_poz++;
	}

	if (cnt_poz == 1) {
		if (mat[i - 1][j] == '.') {
			mat[i][j] = 'v'; mat[i - 1][j] = '^';
			fillV(i - 1, j);
		}
		if (mat[i][j + 1] == '.') {
			mat[i][j] = '<'; mat[i][j + 1] = '>';
			fillV(i, j + 1);
		}
		if (mat[i + 1][j] == '.') {
			mat[i][j] = '^'; mat[i + 1][j] = 'v';
			fillV(i + 1, j);
		}
		if (mat[i][j - 1] == '.') {
			mat[i][j] = '>'; mat[i][j - 1] = '<';
			fillV(i, j - 1);
		}
	}
}

void fillV(int i, int j) {
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k],
			nj = j + dj[k];
		if (mat[ni][nj] == '.') fil(ni, nj);
	}
}

void afisare(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mat[i][j];
		}
		cout << "\n";
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	citire(n, m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == '.') fil(i, j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == '.') {
				cout << "altadata";
				return 0;
			}
		}
	}

	afisare(n, m);
	
	return 0;
}