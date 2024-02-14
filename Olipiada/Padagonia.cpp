///REZOLVARE DE 50 DE PUNCTE
#include <fstream>
#define MOD 666013

typedef long long LL;

using namespace std;

ifstream fin("patagonia.in");
ofstream fout("patagonia.out");

int mat[1010][1010];
LL C, n, m, v, k;
LL cnt_zone;

void flag(int i, int j){
    for (int l = 1; l <= m; l++)
        if (mat[i][l] == 0) {
            mat[i][l] = -1;
            cnt_zone--;
        }
    for (int l = 1; l <= n; l++)
        if (mat[l][j] == 0) {
            mat[l][j] = -1;
            cnt_zone--;
        }
}

void zone_sigure(){
    cnt_zone = n * m - v;
    while (v){
        int i, j;
        fin >> i >> j;
        mat[i][j] = 1;

        v--;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (mat[i][j] == 1) {
                    flag(i, j);

                mat[i][j] = -1;
            }
        }
    }

}

LL factMod(LL n) {
    LL rez = 1;
    for (LL i = 2; i <= n; i++){
        rez  = rez * i % MOD;
    }

    return rez % MOD;
}

LL modPow(LL b, LL e) {
    LL rez = 1;
    while (e) {
        if (e & 1)
            rez = rez * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }

    return rez % MOD;
}

LL invMod(LL a, LL b) {
    return modPow(a * b % MOD, MOD - 2);
}

LL solve(){
    LL sus = factMod(k + cnt_zone - 1);
    LL jos = invMod(factMod(cnt_zone - 1), factMod(k));
    return sus * jos % MOD;
}

int main()
{
    fin >> C >> n >> m >> v >> k;
    zone_sigure();
    if (C == 1) fout << cnt_zone;
    else {
        if (cnt_zone == 0) fout << 0;
        else
            fout << solve();
    }

    return 0;
}
