//REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

char A[2000001], B[2000001];
int pref[2000001];
int matches[2000001];
int cnt_match;

int nA, nB;

void formare_prefix() {
    int i = 0, j = -1;
    pref[0] = -1;

    while (i < nA) {
        while (j >= 0 && A[i] != A[j])
            j = pref[j];

        j++;
        i++;
        pref[i] = j;
    }
}

void KMP() {
    int i = 0, j = 0;

    while (i < nB) {
        while (j >= 0 && B[i] != A[j])
            j = pref[j];

        i++;
        j++;
        if (j == nA) {
            j = pref[j];
            matches[cnt_match++] = i - nA;
        }
    }
}

int main()
{
    fin.getline(A, 2000001);
    fin.getline(B, 2000001);

    nA = strlen(A);
    nB = strlen(B);

    formare_prefix();
    KMP();

    fout << cnt_match << "\n";

    if (cnt_match > 1000) cnt_match = 1000;

    for (int i = 0; i < cnt_match; i++)
        fout << matches[i] << " ";

    return 0;
}
