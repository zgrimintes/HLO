///Ineficient

#include <iostream>

using namespace std;

void citire(int a[], int n) {
    if (n == 0) return;

    citire(a, n - 1);
    cin >> a[n];
}

void afisare(int a[], int n) {
    if (n == 0) return;

    afisare(a, n - 1);
    cout << a[n] << " ";
}

void sor(int a[], int n, int i, int j)
{
    if (i < n)
    {
        if (j <= n)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
            sor(a, n, i, j + 1);
        }
        else
        {
            sor(a, n, i + 1, i + 2);
        }
    }
}

void sortare(int a[], int n, int i, int j) {
    if (i >= n) return;

    if (j <= n) {
        if (a[i] > a[j])
            swap(a[i], a[j]);
        sortare(a, n, i, j + 1);
    }
    else
        sortare(a, n, i + 1, i + 2);
}

int main() {
    int a[100], n;
    cin >> n;
    citire(a, n);
    sortare(a, n, 1, 2);
    afisare(a, n);

    return 0;
}
