#include <fstream>

using std::pair;

std::ifstream cin("intersectiesegmente.in");
std::ofstream cout("intersectiesegmente.out");

int x1, x2, Y1, y2, x3, y3, y4, x4;

bool isEqual(pair<int, int> m1, pair<int, int> m2) {
	return (m1.first == m2.second) && (m1.second == m2.first);
}

int main()
{
	cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	pair <int, int> m1, m2;
	m1.first = Y1 - y2; m2.first = y3 - y4;
	m1.second = x1 - x2; m2.second = x3 - x4;

	if (isEqual(m1, m2)) {
		cout << "NU";
		return 0;
	}
	else {
		int xp;
		int coef_x1, coef_y1, coef_x2, coef_y2, lib1, lib2;
		coef_x1 = Y1 - y2;
		coef_y1 = x2 - x1;
		coef_x2 = y3 - y4;
		coef_y2 = x4 - x3;
		lib1 = x1 * y2 - x2 * Y1;
		lib2 = x3 * y4 - x4 * y3;

		if (coef_x1 * coef_y2 - coef_x2 * coef_y1) xp = (coef_y1 * lib2 - coef_y2 * lib1) / (coef_x1 * coef_y2 - coef_x2 * coef_y1);
		else xp = 0;

		if ((xp >= x1 && xp <= x2) && (xp >= x3 && xp <= x4))
			cout << "DA";
		else
			cout << "NU";
	}

	return 0;
}
