#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("ariatriunghi.in");
ofstream fout("ariatriunghi.out");

struct Punct
{
	int x, y;
};

Punct p[3];
float arie;

float det() {
	return p[0].x * (p[1].y - p[2].y) - p[0].y * (p[1].x - p[2].x) + (p[1].x * p[2].y + p[1].y * p[2].x);
}

float detArie() {
	arie = 0;

	float determinata = det();
	arie = determinata / 2;

	if (arie < 0) arie = 0 - arie;
}

int main() {
	for (int i = 0; i < 3; i++)
		fin >> p[i].x >> p[i].y;

	detArie();

	fout << fixed << setprecision(1) << arie;
}
