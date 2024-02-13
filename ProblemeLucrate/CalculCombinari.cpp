//REZOLVARE CLASICA CU FORMULA COMBINARILOR
#include <iostream>

typedef long long LL;

using namespace std;

int N[1001];
int n, k;

void multiplication(LL n) {
	int t = 0;
	for (int i = 1; i <= N[0]; i++) {
		t = N[i] * n + t;
		N[i] = t % 10;
		t /= 10;
	}

	while (t) {
		N[0]++;
		N[N[0]] = t % 10;
		t /= 10;
	}
}

void division(LL n) {
	int r = 0;
	for (int i = N[0]; i > 0; i--) {
		r = r * 10 + N[i];
		N[i] = r / n;
		r = r % n;
	}

	while (N[N[0]] == 0 && N[0] > 1) N[0]--;
}

void solve() {
	for (int i = 1; i <= k; i++) {
		multiplication(n - k + i);
		division(i);
	}
}

void afisare() {
	for (int i = N[0]; i > 0; i--)
		cout << N[i];
}

int main() {
	N[0] = N[1] = 1;
	cin >> n >> k;
	solve();
	afisare();
	return 0;
}



///REZOLVARE CU TRIUNGHIUL LUI PASCAL PE NUMERE MARI
#include <iostream>

using namespace std;

int pascal_N[505][1001];
int n, k;

void adition(int n1[], int n2[]) {
	int lng = max(n1[0], n2[0]);

	for (int i = n1[0] + 1; i <= lng; i++) n1[i] = 0;
	for (int i = n2[0] + 1; i <= lng; i++) n2[i] = 0;

	n1[0] = lng;
	int t = 0;

	for (int i = 1; i <= n1[0]; i++) {
		n1[i] = n1[i] + n2[i] + t;
		t = n1[i] / 10;
		n1[i] %= 10;;
	}

	if (t) {
		n1[0]++;
		n1[n1[0]] = t;
	}
}

void form_pascal() {
	pascal_N[0][0] = pascal_N[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			adition(pascal_N[j], pascal_N[j - 1]);
		}
	}
}

void afisare() {
	for (int i = pascal_N[k][0]; i > 0; i--)
		cout << pascal_N[k][i];
}

int main() {
	cin >> n >> k;
	form_pascal();
	afisare();

	return 0;
}
