#include <iostream> 

using namespace std;

int arr[1000000];

void citire(int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int partition(int l, int r) {
	int pivot = arr[r];

	int i = l - 1;

	for (int j = l; j <= r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void quickSort(int l, int r) {
	if (l >= r) return;

	int pi = partition(l, r);

	quickSort(l, pi - 1);
	quickSort(pi + 1, r);
}

void afisare(int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main() {
	int n;
	cin >> n;
	citire(n);
	quickSort(0, n - 1);
	afisare(n);

	return 0;
}
