#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[1000];

void citire(int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i].first, arr[i].second = i + 1;
}

bool ok(const pair <int, int> a, const pair <int, int> b) {
	return a.first < b.first;
}

void solve(int n, int x) {
	sort(arr, arr + n, ok);

	int p1, p2;

	for (p1 = 0; p1 < n - 3; p1++) {
		for (p2 = 1; p2 < n - 2; p2++) {
			int p3 = p2 + 1, p4 = n - 1;

			while (p3 < p4) {
				int sum = arr[p1].first + arr[p2].first;
				sum += arr[p3].first + arr[p4].first;

				if (sum == x) {
					cout << arr[p1].second << " " << arr[p2].second << " " << arr[p3].second << " " << arr[p4].second;
					return;
				}
				else if (sum > x) {
					p4--;
				}
				else {
					p3++;
				}
			}
		}
	}

	cout << "IMPOSSIBLE";
}

int main() {
	int n, x; cin >> n >> x;
	citire(n);

	solve(n, x);

	return 0;
}
