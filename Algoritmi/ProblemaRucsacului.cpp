///REZOLVARE PE O LINIE LUATA DE LA COADA LA INCEPUT
#include <fstream>

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int n, G;
int dp[10001];
int w[5001], p[5001];

void citire(){
    int i = 0, j = 0;
    int cn = n;
    while (cn){
        fin >> w[i++] >> p[j++];
        cn--;
    }
}

int solve(){
    for (int i = 0; i < n; i++) {
        for (int j = G; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }


    return dp[G];
}

int main()
{
    fin >> n >> G;
    citire();
    fout << solve();

    return 0;
}
