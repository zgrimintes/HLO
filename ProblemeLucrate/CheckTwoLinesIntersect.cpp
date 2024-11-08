#include <iostream>

using namespace std;

struct Point
{
	int x, y;
};

bool onSegment(Point a, Point b, Point c) {
	if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) &&
		b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y))

		return true;

	return false;
}

int getOrientation(Point a, Point b, Point c) {
	int det = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);

	if (!det) return det;

	return det > 0 ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
	int o1 = getOrientation(p1, q1, p2);
	int o2 = getOrientation(p1, q1, q2);
	int o3 = getOrientation(p2, q2, p1);
	int o4 = getOrientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4) return true;

	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; 
}

int main() {
	
	struct Point p1 = { 1, 1 }, q1 = { 10, 1 };
	struct Point p2 = { 1, 2 }, q2 = { 10, 2 };

	doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

	p1 = { 10, 0 }, q1 = { 0, 10 };
	p2 = { 0, 0 }, q2 = { 10, 10 };
	doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

	p1 = { -5, -5 }, q1 = { 0, 0 };
	p2 = { 1, 1 }, q2 = { 10, 10 };
	doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

	return 0;
	
	return 0;
}
