//METODA TRAPEZULUI
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("aria.in");
ofstream fout("aria.out");

struct Punct
{
	long double x, y;
};

int n;
long double arie;
Punct p[100005];

void citire() {
	for (int i = 0; i < n; i++)
		fin >> p[i].x >> p[i].y;
}

void calculArie() {
	Punct p1, p2;
	int cnt1 = 0, cnt2 = 1;
	p1 = p[cnt1 % n];
	p2 = p[cnt2 % n];

	while (p2.x != p[0].x || p2.y != p[0].y)
	{
		arie += (p1.y + p2.y) * (p2.x - p1.x);

		cnt1++;
		cnt2++;
		p1 = p[cnt1 % n];
		p2 = p[cnt2 % n];
	}

	arie += (p1.y + p2.y) * (p2.x - p1.x);
}

int main() {
	fin >> n;
	citire();

	calculArie();

	fout << setprecision(5) << fixed;
	fout << abs(arie / 2);

	return 0;
}
