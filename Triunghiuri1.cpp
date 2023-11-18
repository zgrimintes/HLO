#include <iostream>
#include <algorithm>

using namespace std;

void citire(int a[], int n) {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int get_largest_power(int n) {
    int lg = 1;

    for (; lg < n; lg <<= 1);

    return lg;
}

int cautare_bin(int a[], int n, int x) {
    int lg = get_largest_power(n);
    int poz = 0;

    for (; lg != 0; lg >>= 1) {
        if (poz + lg < n && a[poz + lg] < x)
            poz += lg;
    }

    return poz;
}

int main()
{
    int vect[1000];
    int n;
    int cnt_tri = 0;
    cin >> n;

    citire(vect, n);
    sort(vect, vect + n);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        //Petru fiecare numar incerc sa fac triunghiuri cu toate numerele cu care nu am mai facut pana atunci
        //Apoi iau suma celor doua si caut in sir pozitia ultimului numar care poate forma un triunghi
        //In final adaug la contor diferenta dintre pozitia ultimului nr si numarului actual cu care am facut triunghiul
        for (int j = i + 1; j < n; j++) { 
            sum = vect[i] + vect[j];
            cnt_tri += cautare_bin(vect, n, sum) - j;
        }
    }

    cout << cnt_tri;

    return 0;
}
