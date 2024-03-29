///REZOLVARE DE 100 DE PUNCTE
#include <fstream>
#include <stack>
#include <algorithm>
#include <iomanip>

#define NMAX 1000000001

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

struct Punct
{
	double x, y, m;
};

stack <Punct> S;
Punct p[120001];
Punct ps[120001];
int n;
int ind_p;
int i_min = NMAX;

void citirePuncte() {
	int next = 0;
	int cn = n;
	while (cn) {
		fin >> p[ind_p].x >> p[ind_p].y;

        if (i_min == NMAX || p[ind_p].x < p[i_min].x)
            i_min = ind_p;
        else if (p[ind_p].x == p[i_min].x)
            if (p[ind_p].y < p[i_min].y)
                i_min = ind_p;

			ind_p++;
			cn--;
	}

	S.push(p[i_min]);

	Punct aux;
	aux = p[i_min];
	p[i_min] = p[0];
	p[0] = aux;
}

bool cmp(Punct p1, Punct p2) {
	return p1.m < p2.m;
}

bool det(Punct a, Punct b, Punct c) {
	double D =	a.x * b.y + b.x * c.y + a.y * c.x -
				(c.x * b.y + a.y * b.x + c.y * a.x);

	return D >= 0;
}

void infasura() {
	S.push(p[1]);

	for (int i = 2; i < n; i++) {
		Punct ps1, ps2;
		ps1 = S.top(); S.pop();
		ps2 = S.top();
		S.push(ps1);

		if (det(ps2, ps1, p[i])) {
			S.push(p[i]);
		}
		else {
			while (!det(ps2, ps1, p[i]) && S.size() >= 2) {
				S.pop();
				ps1 = S.top(); S.pop();
				ps2 = S.top();
				S.push(ps1);
			}
			S.push(p[i]);
		}
	}
}

void getSlope() {
	for (int i = 1; i < n; i++) {
		if (p[i].x == p[0].x) p[i].m = NMAX;
		else p[i].m = ((p[i].y - p[0].y) / (p[i].x - p[0].x));
	}
}

void afisare() {
	fout << S.size() << "\n";
	int i = 1, limit = S.size();

	for (; i <= limit; i++) {
		ps[i] = S.top();
		S.pop();
	}
	ps[0] = ps[i - 1];

	for (int j = i - 2; j >= 0; j--) {
		fout << fixed << setprecision(6) << ps[j].x << " " << ps[j].y << "\n";
	}
}

int main() {
	fin >> n;
	citirePuncte();
	getSlope();
	sort(p + 1, p + n, cmp);
	infasura();
	afisare();
	return 0;
}
