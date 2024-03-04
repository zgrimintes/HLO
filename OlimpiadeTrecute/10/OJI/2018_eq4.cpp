///57 PUNCTE, C2 CORECTA PARTIAL
#include <fstream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

ifstream fin("eq4.in");
ofstream fout("eq4.out");

LL rez;
LL nec[4];
int c, a, b, E;
char ex[100001];
LL rezs[2][1000001];
int ind_r, cnt_r;
int p;

void getNb(char s) {
	int nb = 0;
	for (; ex[p] >= '0' && ex[p] <= '9'; p++)
		nb = nb * 10 + ex[p] - '0';

	if (nb == 0) nb = 1;

	switch (ex[p])
	{
	case 'x':
		(s == '+') ? nec[0] += nb : nec[0] -= nb;
		p++;
		break;
	case 'y':
		(s == '+') ? nec[1] += nb : nec[1] -= nb;
		p++;
		break;
	case 'z':
		(s == '+') ? nec[2] += nb : nec[2] -= nb;
		p++;
		break;
	case 't':
		(s == '+') ? nec[3] += nb : nec[3] -= nb;
		p++;
		break;
	default:
		(s == '+') ? rez += nb : rez -= nb;
		break;
	}
}

void getEq() {
	for (int i = a; i <= b; i++) {
		LL cpy[4];

		cpy[0] = nec[0] * i;
		cpy[2] = nec[2] * i;
		for (int j = a; j <= b; j++) {
			cpy[1] = nec[1] * j;
			cpy[3] = nec[3] * j;

			rezs[0][ind_r] = cpy[0] + cpy[1] + rez;
			rezs[1][ind_r] = E - cpy[2] - cpy[3];
			ind_r++;
		}
	}

	sort(rezs[0], rezs[0] + ind_r);

	for (int i = 0; i < ind_r; i++)
		if (binary_search(rezs[0], rezs[0] + ind_r, rezs[1][i])) cnt_r++;
}

void solve() {
	int len = strlen(ex);
	while (p < len) {
		switch (ex[p])
		{
		case '+':
			p++;
			getNb('+');
			break;
		case '-':
			p++;
			getNb('-');
			break;
		default:
			break;
		}
	}

	if (c == 1) fout << rez + nec[0] + nec[1] + nec[2] + nec[3];
	else {
		getEq();
		fout << cnt_r;
	}
}

int main() {
	fin >> c;
	fin.get();
	fin.getline(ex, 100001);
	fin >> a >> b >> E;
	solve();
	return 0;
}
