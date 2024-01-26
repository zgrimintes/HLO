#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("sirpie.in");
ofstream fout("sirpie.out");

int ap[10], sol[10], num[10];
int n;

int cmmdc(int n, int m){
    int r;
    while (m){
        r = n % m;
        n = m;
        m = r;
    }

    return n;
}

void afis(){
    for (int i = 0; i < n; i++) {
        fout << num[sol[i]] << " ";
    }
    fout << "\n";
}

void backtrack(int k) {
    if (k == n) {
        afis();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (ap[i] == 0) {
            if (cmmdc(num[i], num[sol[k - 1]]) == 1 || k == 0) {
                ap[i] = 1;
                sol[k] = i;
                backtrack(k + 1);
                ap[i] = 0;
            }

        }
    }

}

int main()
{
    int nr;
    fin >> n;

    for (int i = 0; i < n; i++){
        fin >> nr;
        num[i] = nr;
    }

    sort(num, num + n);

    backtrack(0);

    return 0;
}
