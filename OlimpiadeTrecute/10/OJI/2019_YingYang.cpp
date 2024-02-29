#include <fstream>

using namespace std;

ifstream fin("yingyang.in");
ofstream fout("yingyang.out");

int n, m;
int mat[105][105];

void citire() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fin >> mat[i][j];
}

int main() {
	fin >> n >> m;
	citire();

	return 0;
}
