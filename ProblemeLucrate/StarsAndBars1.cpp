//REZOLVARE DE 90 DE PUNCTE
//ne folosim de triunghiul lui Pascal cu numere mari
#include <iostream>

using namespace std;

int pascal_mari[1001][1001];

void adition(int nA[1001], int nB[1001]){
    int lng;
    lng = max(nA[0], nB[0]);

    for(int i = nA[0] + 1; i <= lng; i++)
        nA[i] = 0;
    for(int i = nB[0] + 1; i <= lng; i++)
        nB[i] = 0;

    nA[0] = lng;
    int t = 0;
    for (int i = 1; i <= nA[0]; i++) {
        nA[i] = nA[i] + nB[i] + t;
        t = nA[i] / 10;
        nA[i] = nA[i] % 10;
    }

    if (t != 0){
        nA[0]++;
        nA[nA[0]] = t;
    }
}

void afisare(int nM[1001], int n) {
    for (int i = n; i > 0; i--)
        cout << nM[i];
}

void combinations(int n, int k){
    for (int i = 1; i <= n + k; i++) {
        pascal_mari[0][0] = pascal_mari[0][1] = 1;
        for (int j = i; j > 0; j--) {
            adition(pascal_mari[j], pascal_mari[j - 1]);
        }
    }

    afisare(pascal_mari[n], pascal_mari[n][0]);
}

int main()
{
    int n, k;
    cin >> n >> k;
    combinations(n , k - 1);

    return 0;
}

//REZOLVARE DE 100 DE PUNCTE 
//Simplificam ecuatia fara a calcula toate combiatiile
#include <iostream>

using namespace std;

int rez[1001];

void afisare() {
    for (int i = rez[0]; i > 0; i--)
        cout << rez[i];
}

void multiplication(int rez[1001], int n) {
    int t = 0;
    for (int i = 1; i <= rez[0]; i++){
        t += rez[i] * n;
        rez[i] = t % 10;
        t /= 10;
    }

    while (t) {
        rez[0]++;
        rez[rez[0]] = t % 10;
        t /= 10;
    }
}

void division(int rez[1001], int n) {
    int r = 0;
    for (int i = rez[0]; i > 0; i--) {
        r = r  * 10 + rez[i];
        rez[i] = r / n;
        r = r % n;
    }

    while (rez[rez[0]] == 0 && rez[0] > 1)
        rez[0]--;
}

void combinations(int n, int k){
    rez[0] = rez[1] = 1;
    for (int i = 1; i <= k; i++) {
        multiplication(rez, i + n);
        division(rez, i);
    }

    afisare();
}

int main()
{
    int n, k;
    cin >> n >> k;
    combinations(n , k - 1);

    return 0;
}
