//PROBLEMA NETERMINATA, DE TERMINAT
#include <iostream>
#include <algorithm>

using namespace std;

void citire(int a[], int n) {
    for (int i = 0; i < n; i++)
        fin >> a[i];
}

int get_largest_power(int n) {
    int lg = 1;

    for (lg; lg < n; lg <<= 1);
}

void cautare_bin(int a[], int n) {
    int lg = get_largest_power(n);
    int poz = 0;
}

int main()
{
    int vect[1000];
    int n;
    int cnt_tri = 0;
    cin >> n;

    citire(vect, n);
    sort(vect, vect + n - 1);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1 + 1; j < n; j++) {
            sum = vect[i] + vect[j];
            cautare_bin(vect, sum);
        }
    }

    return 0;
}
