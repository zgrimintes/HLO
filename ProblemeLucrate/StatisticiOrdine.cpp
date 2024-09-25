#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("statisticiordine.in");
ofstream fout("statisticiordine.out");

unsigned int arr[4000005];

void citire(int n) {
	for (int i = 1; i <= n; i++)
		fin >> arr[i];
}

int partition(unsigned int k, int l, int r) {
	int pivot = arr[r];

	int i = l - 1;

	for (int j = l; j < r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void quickSelect(unsigned int k, int l, int r) {
	if (k < 0) return;

	int pi = partition(k, l, r);
	
	if (pi > k) quickSelect(k, l, pi - 1);
	else if (pi < k) quickSelect(k, pi + 1, r);
}

int main() {
	unsigned int n, k; fin >> n >> k;
	citire(n);

	quickSelect(k, 1, n);

	fout << arr[k];

	return 0;
}
