#include <iostream> 

using namespace std;

struct Point
{
	double x, y;
};

bool onSegment(Point a, Point b, Point c) {
	if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) &&
		b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y))

		return true;

	return false;
}

int getOrientation(Point a, Point b, Point c) {
	double det = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

	if (!det) return det;

	return det > 0 ? 1 : 2;
}

bool doIntersect(Point x1, Point y1, Point x2, Point y2, Point& intersection) {
	int o1 = getOrientation(x1, y1, x2);
	int o2 = getOrientation(x1, y1, y2);
	int o3 = getOrientation(x2, y2, x1);
	int o4 = getOrientation(x2, y2, y1);

	if (o1 != o2 && o3 != o4) {
		double a1 = y1.y - x1.y;
		double b1 = x1.x - y1.x;
		double c1 = a1 * x1.x + b1 * x1.y;

		double a2 = y2.y - x2.y;
		double b2 = x2.x - y2.x;
		double c2 = a2 * x2.x + b2 * x2.y;

		double det = a1 * b2 - a2 * b1;

		if (det != 0) {
			intersection.x = (c1 * b2 - c2 * b1) / det;
			intersection.y = (a1 * c2 - a2 * c1) / det;

			return true;
		}
	}

	if (o1 == 0 && onSegment(x1, x2, y1))
		return true;
	if (o2 == 0 && onSegment(x1, y2, y1))
		return true;

	return false;
}

int main() {
	Point p1 = { 2, 3 }, q1 = { 5, 7 };
	// Define second line segment
	Point p2 = { 3, 9 }, q2 = { 6, 2 };
	// Point to store the intersection
	Point intersection;

	// Check if the lines intersect and print the result
	if (doIntersect(p1, q1, p2, q2, intersection)) {
		cout << "The lines intersect at point ("
			<< intersection.x << ", " << intersection.y
			<< ")." << endl;
	}
	else {
		cout << "The lines do not intersect within the "
			"segments."
			<< endl;
	}


	return 0;
}
