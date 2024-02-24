#include <fstream>
#include <stack>
#include <algorithm>

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

struct Punct
{
	float x, y;
};

stack <Punct> S;
Punct p[120001];
int n;
int ind_p;
int i_min = 1000000001;

void citirePuncte() {
	int next = 0;
	int cn = n;
	while (cn) {
		char temp;
		int i, j;

		fin >> i;
		fin >> temp;
		fin >> j;
		next++;
		
		if (next % 2 == 0) {
			p[ind_p].y = (float)((i * 10 + j) / 10);

			if (i_min == 1000000001 || p[ind_p].x < p[i_min].x)
				i_min = ind_p;
			else if (p[ind_p].x == p[i_min].x)
				if (p[ind_p].y < p[i_min].y)
					i_min = ind_p;

			ind_p++;
			cn--;
		}
		else p[ind_p].x = (float)((i * 10 + j) / 10);
	}

	S.push(p[i_min]);

	Punct aux;
	aux = p[i_min];
	p[i_min] = p[0];
	p[0] = aux;
}

bool cmp(Punct p1, Punct p2) {
	if (p1.x < p2.x) return false;
	if (p1.y < p2.y) return true;

	return true;
}

int main() {
	fin >> n;
	citirePuncte();
	sort(p, p + n, cmp);

	return 0;
}
