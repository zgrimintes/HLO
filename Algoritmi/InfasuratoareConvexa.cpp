#include <fstream>
#include <stack>
#include <algorithm>

#define NMAX 1000000001

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

struct Punct
{
	float x, y, m;
};

stack <Punct> S;
Punct p[120001];
int n;
int ind_p;
int i_min = NMAX;

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

			if (i_min == NMAX || p[ind_p].x < p[i_min].x)
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
	if (p1.x < p2.x) return true;
	if (p1.y < p2.y) return false;

	return false;
}

bool det(Punct a, Punct b, Punct c) {
	float D =	a.x * b.y + b.x * c.y + a.y * c.x -
				c.x * b.y - a.y * b.x * c.y * a.x;

	return D >= 0;
}

void infasura() {
	S.push(p[1]);
	S.push(p[2]);

	for (int i = 3; i < n; i++) {
		Punct ps1, ps2;
		ps1 = S.top(); S.pop();
		ps2 = S.top();
		S.push(ps1);

		if (det(ps2, ps1, p[i])) {
			S.push(p[i]);
		}
		else {
			while (!det(ps2, ps1, p[i])) {
				S.pop();
				ps1 = S.top(); S.pop();
				ps2 = S.top();
				S.push(ps1);
				S.push(p[i]);
			}
		}
	}
}

int main() {
	fin >> n;
	citirePuncte();
	sort(p + 1, p + n, cmp);
	infasura();
	fout << S.size();
	return 0;
}
