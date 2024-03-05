#include <iostream>
#include <fstream>

std::ifstream cin("moscraciun.in");
std::ofstream cout("moscraciun.out");

std::pair<int, int> posM;
int nord[105][105];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int cnt_spir = 0;

void citire(int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> nord[i][j];
			if (nord[i][j] == 2) {
				posM.first = i;
				posM.second = j;
			}
		}
}

void bordare(int n, int m) {
	for (int i = 0; i <= n + 1; i++)
		nord[i][0] = nord[i][m + 1] = -1;

	for (int i = 0; i <= m + 1; i++)
		nord[0][i] = nord[n + 1][i] = -1;
}

void fill(int i, int j) {
	if (nord[i][j] < 1) return;

	if (nord[i][j] == 3) cnt_spir++;
	nord[i][j] = -1;
	
	for (int k = 0; k < 4; k++)
		fill(i + di[k], j + dj[k]);
}

int main() {
	int n, m;
	cin >> n >> m;
	citire(n, m);
	bordare(n, m);
	fill(posM.first, posM.second);

	cout << cnt_spir;
	return 0;
}
