#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n;
int A[1025], B[1025];
int dp[1025][1025];
int rasp[1025];
int ind_rasp;

void citire() {
    for (int i = 1; i <= m; i++)
        fin >> A[i];
    for (int i = 1; i <= n; i++)
        fin >> B[i];
}

int solve() {

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));

    return dp[m][n];
}

void formRasp() {
    ind_rasp = dp[m][n];

    int i = m, j = n;
    while (i != 0 && j != 0) {
        if (A[i] == B[j]) {
            rasp[ind_rasp--] = A[i];
            i--, j--;
        }
        else {
            if (dp[i - 1][j] >= dp[i][j - 1]) i--;
            else j--;
        }
    }

}

void afisare() {
    for (int i = 1; i <= dp[m][n]; i++)
        fout << rasp[i] << " ";
}

int main()
{
    fin >> m >> n;
    citire();

    fout << solve() << "\n";
    formRasp();
    afisare();

    return 0;
}
