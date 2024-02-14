///REZOLVARE DE 70 DE PUNCTE
#include <fstream>

using namespace std;

ifstream fin("parc.in");
ofstream fout("parc.out");

int dI[4] = {-1, 0, 1, 0},
    dJ[4] = {0, 1, 0, -1};

int parc[1005][1005];
int cpy[1005][1005];
int n, m, C, L;
int cnt_lac, cnt_buc;
int max_den;

void citire(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            fin >> parc[i][j];
            if (parc[i][j] > max_den) max_den = parc[i][j];
        }
}

void cpyMat(){
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++){
            cpy[i][j] = parc[i][j];
        }
}

void bordare(){
    for (int i = 0; i <= n + 1; i++)
        parc[i][0] = parc[i][m + 1] = -1;

    for (int j = 0; j <= n + 1; j++)
        parc[0][j] = parc[n + 1][j] = -1;
}

void fill_Lac(int i, int j) {
    if (i < 0 || j < 0 || j >= m + 1 || i >= n + 1) return;
    if (cpy[i][j] >= L) return;
    if (cpy[i][j] < 0) return;

    cpy[i][j] = -1;
    cnt_buc++;

    for (int k = 0; k < 4; k++)
        fill_Lac(i + dI[k], j + dJ[k]);
}

int main()
{
    fin >> C >> n >> m;
    citire();
    bordare();
    cpyMat();

    if (C == 1){
        fin >> L;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                if (cpy[i][j] < L && cpy[i][j] >= 0){
                    fill_Lac(i, j);
                    cnt_lac++;
                }

            }

        fout << cnt_lac;
    }
    else if(C == 2){
        L = max_den;
        while (L > 0){
            for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++){if (cpy[i][j] < L && cpy[i][j] >= 0){
                        fill_Lac(i, j);
                        cnt_lac++;
                    }

                }
            if (cnt_lac != 1) {
                L++;
                break;
            }

            L--;
            cpyMat();
            cnt_lac = 0;
        }

        fout << L;
    }
    else {
        L = 1;
        long long min_dif = 1000000001;

        while (L < max_den) {

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++){
                    if (cpy[i][j] < L && cpy[i][j] >= 0){
                        fill_Lac(i, j);
                    }

                }

            long long dif = max(n * m - cnt_buc, cnt_buc) - min(n * m - cnt_buc, cnt_buc);

            if (dif <= min_dif) min_dif = dif;
            else break;

            L++;
            //cpyMat();
            //cnt_buc = 0;
        }

        fout << L - 1;
    }

    return 0;
}
