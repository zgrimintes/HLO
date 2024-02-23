///REZOLVARE DE 100 DE PUNCTE
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("ariepoligonsimplu.in");
ofstream fout("ariepoligonsimplu.out");

struct Punct
{
	int x, y;
};

Punct p[10001];
int n;
float arie;

float det(int i, int j, int k) {
	return (p[j].x - p[i].x) * (p[k].y - p[i].y) - (p[k].x - p[i].x) * (p[j].y - p[i].y);
}

void detArie() {
	p[n] = p[0];
	for (int i = 2; i < n; i++) 
		arie += det(1, i, i + 1);
	
	arie /= 2.0;
}

int main() {
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> p[i].x >> p[i].y;

	detArie();

	fout << fixed << setprecision(1) << arie;
}
