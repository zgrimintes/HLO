///REZOLVARE DE 20 DE PUNCTE - C1
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

ifstream fin("miting.in");
ofstream fout("miting.out");

struct Tinar
{
	int x, y;
	char lit;
};

queue <pair <int, int>> Q;
Tinar tineri[11];
int c, n, m, ind_t;
char cuv[1000];
int mat[65][65];
int i_min = 100, j_min = 100, i_max, j_max;

void citire() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char temp;
			fin >> temp;
			switch (temp)
			{
			case '#':
				mat[i][j] = 0;
				break;
			case '_':
				mat[i][j] = 1;
				break;
			default:
				tineri[ind_t++].x = i;
				tineri[ind_t++].y = j;
				tineri[ind_t++].lit = temp;

				if (i < i_min) i_min = i;
				if (j < j_min) j_min = j;

				if (i > i_max) i_max = i;
				if (j > j_max) j_max = j;
					
				break;
			}
		}
}

int main() {
	fin >> c >> n >> m;
	fin.get();
	fin.getline(cuv, 1000);
	citire();

	if (c == 1) {
		fout << (i_max - i_min + 1) * (j_max - j_min + 1);
	}
	else {

	}

	return 0;
}
