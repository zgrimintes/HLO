//REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cautbin.in");
ofstream fout("cautbin.out");

void citire(int a[], int n) {
    for (int i = 0; i < n; i++)
        fin >> a[i];
}

int get_largest_power(int n) {
    int lg = 1;

    for (; lg < n; lg <<= 1);

    return lg;
}

int cerinta1(int a[], int x, int n) {
    int lg = get_largest_power(n);
    int poz = 0;

    for (lg; lg != 0; lg >>= 1) {
        if (lg + poz < n && a[lg + poz] <= x)
            poz += lg;
    }

    if (a[poz] == x)
        return poz;
    return -2;

}

int cerinta2(int a[], int x, int n) {
    int lg = get_largest_power(n);
    int poz = 0;

    for (lg; lg != 0; lg >>= 1) {
        if (lg + poz < n && a[lg + poz] <= x)
            poz += lg;
    }

    return poz;
}

int cerinta3(int a[], int x, int n) {
    int lg = get_largest_power(n);
    int poz = n - 1;

    for (lg; lg != 0; lg >>= 1) {
        if (poz - lg >= 0 && a[poz - lg] >= x)
            poz -= lg;
    }

    return poz;
}

int main()
{
    int vect[100000];
    int n, m, C, x;

    fin >> n;
    citire(vect, n);

    fin >> m;
    while (m) {
        fin >> C >> x;

        switch (C) {
        case 0:
            fout << cerinta1(vect, x, n) + 1 << '\n';
            break;
        case 1:
            fout << cerinta2(vect, x, n) + 1 << '\n';
            break;
        case 2:
            fout << cerinta3(vect, x, n) + 1 << '\n';
            break;
        }

        m--;
    }

    return 0;
}
