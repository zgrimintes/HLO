#include <fstream>
#include <limits.h>

using namespace std;

ifstream fin("podm.in");
ofstream fout("podm.out");

long long dp[501][501];
long long d[501];
int n;

void citire(){
    for (int i = 0; i <= n; i++)
        fin >> d[i];
}

long long solve(){
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int i = 1; i < n; i++) dp[i][i + 1] = d[i - 1] * d[i] * d[i + 1];

    for (int i = 1; i <= n; i++){
        int ci = 1;
        for (int j = i + 2; j <= n; j++){
            dp[ci][j] = LLONG_MAX;
            for (int k = ci; k < j; k++) {
                dp[ci][j] = min(dp[ci][k] + dp[k + 1][j] + d[ci - 1] * d[k] * d[j], dp[ci][j]);
            }

            ci++;
        }
    }

    return dp[1][n];
}

int main()
{
    fin >> n;
    citire();
    fout << solve();

    return 0;
}
