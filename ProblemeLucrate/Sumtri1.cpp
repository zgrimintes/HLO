///REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>

std::ifstream cin("sumtri.in");
std::ofstream cout("sumtri1.out");

int n, cn;
int tri[105][105];
int sumTri[105][105];
int res[105];
int minStart = 10000000;

void citire() {
	for (int i = 1; i <= n; i++) {
		tri[i][0] = sumTri[i][0] = -1;
		tri[i][i + 1] = sumTri[i][i + 1] = - 1;

		for (int j = 1; j <= i; j++)
			cin >> tri[i][j], sumTri[i][j] = tri[i][j];
	}
}

void formSumTri() {
	for (int i = 2; i <= n; i++) {
		sumTri[i][i] += sumTri[i - 1][i - 1];
		sumTri[i][1] += sumTri[i - 1][1];
	}


	for (int i = 3; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			sumTri[i][j] += std::min(sumTri[i - 1][j], sumTri[i - 1][j - 1]);
		}
	}

}

void formResult() {
	int indMin = -1;
	for (int i = 1; i <= n; i++)
		if (sumTri[n][i] < minStart) {
			minStart = sumTri[n][i];
			indMin = i;
		}

	cout << sumTri[n][indMin] << "\n";

	while (n) {
		res[n] = tri[n][indMin];

		if (sumTri[n - 1][indMin] != -1 && sumTri[n - 1][indMin - 1] != -1) {
			if (sumTri[n - 1][indMin] > sumTri[n - 1][indMin - 1]) indMin--;
		}
		else if (sumTri[n - 1][indMin] == -1) indMin--;

		n--;
	}
}

void afisare() {
	for (int i = 1; i <= cn; i++)
		cout << res[i] << " ";
}

int main() {
	cin >> n; cn = n;
	citire();
	formSumTri();
	formResult();
	afisare();

	return 0;
}
