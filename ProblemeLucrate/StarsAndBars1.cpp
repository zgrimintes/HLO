//REZOLVARE DE 90 DE PUNCTE
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
