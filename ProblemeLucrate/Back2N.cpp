#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("back.in");

int a[100], v[100], x[100];
int n;

bool valid(int k) {
    if (k < 1) return 1;

    if (k < n && a[x[k]] < a[x[k - 1]]) return 1;

    if (k < n) return 0;

    if (k >= n + 1) {
        if (a[x[k]] > a[x[k - 1]]) return 0;
    }

    if (a[x[k]] > a[x[k - n]]) return 0;


    return 1;
}

void afisare() {
    for (int i = 0; i < n * 2; i++) {
        if (i == n) cout << "\n";

        cout << a[x[i]] << " ";
    }

    cout << "\n\n";
}

void backT(int k) {
    if (k >= n * 2) {
        afisare();
        return;
    }

    for (int i = 0; i < n * 2; i++) {
        if (v[i]) continue;

        x[k] = i;
        v[i] = 1;

        if (valid(k))
            backT(k + 1);

        x[k] = 0;
        v[i] = 0;
    }
}

int main()
{
    fin >> n;

    for (int i = 0; i < n * 2; i++) fin >> a[i];

    backT(0);
    return 0;
}
