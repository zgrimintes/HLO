///REZOLVARE DE 60 DE PUNCTE
#include <iostream>
#include <fstream>

std::ifstream cin("terencasa_low.in");
std::ofstream cout("terencasa_low.out");

int mat[1001][1001];
int sum[1001][1001];
int n, m;
int max_teren = 0;
int IJ, JJ, IS, JS;

void citire(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
}

void formSum(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
        }
}

void getTeren(){
    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= m; j++) {
            if (mat[i][j] != 1) continue;

            int ci = i, cj = j;
            int cnt_diag = 0;

            while (mat[ci][cj] == 1){
                cnt_diag++;
                int sum_subM = sum[i][j] - sum[i][cj - 1] - sum[ci - 1][j] + sum[ci - 1][cj - 1];

                if (sum_subM != cnt_diag * cnt_diag) {
                    ci--;
                    cj--;
                    continue;
                }

                if (cnt_diag > max_teren) {
                    max_teren = cnt_diag;
                    IJ = i;
                    JJ = j;
                    IS = ci;
                    JS = cj;
                }

                ci--;
                cj--;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    citire();
    formSum();
    getTeren();

    cout << max_teren << "\n" << IS << " " << JS << " " << IJ << " " << JJ;

    return 0;
}
