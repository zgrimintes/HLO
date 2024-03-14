///10 PUNCTE
#include <fstream>

#define MOD 1000000007

using namespace std;

ifstream fin("leftmax.in");
ofstream fout("leftmax.out");

int n;
int pos[100001];
int nr[100001];
int cnt_mod;

void citire(){
    for (int i = 1; i <= n; i++){
        fin >> nr[i];
        pos[nr[i]] = i;
    }

}

void solve(){
    int cnt_temp = 0;
    for (int i = n; i > 0; i--){
        cnt_temp = 0;
        int j = pos[i];
        while (j != 0 && j < n && nr[j + 1] < i){
            cnt_temp = (cnt_temp + 1) % MOD;
            j++;
        }

        int k = pos[i] - 1;
        int t = cnt_temp;
        while (k > 0 && pos[i] - k <= t && nr[k] < i) cnt_temp = cnt_temp * cnt_temp % MOD, k--;
        cnt_mod = (cnt_temp + cnt_mod) % MOD;
    }
}

int main()
{
    fin >> n;
    citire();
    solve();

    fout << cnt_mod + n;
    return 0;
}
