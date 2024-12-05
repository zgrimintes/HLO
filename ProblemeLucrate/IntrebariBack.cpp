#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("int.in");

int arr[100], x[100], v[100];
int n, a, b, p, q;
int cnt = 0;

void afisare(int k) {
    for (int i = 0; i < k; i++)
        cout << arr[x[i]] << " ";
    cout << "\n";
}

void bckT(int k, int s) {
    if (k >= a && k <= b && s >= p) {
        afisare(k);
        //return;
    }

    for (int i = k == 0 ? i = 0 : i = x[k - 1] + 1; i < n; i++) {
        if (v[i]) continue;

        x[k] = i;
        v[i] = 1;
        s += arr[i];

        if (s <= q)
            bckT(k + 1, s);

        s -= arr[i];
        x[k] = 0;
        v[i] = 0;
    }
}

int main()
{
    fin >> n >> a >> b >> p >> q;

    for (int i = 0; i < n; i++)
        fin >> arr[i];

    bckT(0, 0);
    return 0;
}
