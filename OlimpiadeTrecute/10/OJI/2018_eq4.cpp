///24 PUNCTE - C1
#include <fstream>
#include <cstring>

typedef long long LL;

using namespace std;

ifstream fin("eq4.in");
ofstream fout("eq4.out");

LL rez;
LL nec[4];
int c, a, b, E;
char ex[100001];
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
}

int main() {
	fin >> c;
	fin.get();
	fin.getline(ex, 100001);
	fin >> a >> b >> E;
	solve();
	return 0;
}
