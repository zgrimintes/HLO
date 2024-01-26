//REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("permpf.in");
ofstream fout("permpf.out");

int ap[100], sol[10];
int n;

bool check(){
    for (int i = 1; i <= n; i++) {
        if (sol[i-1] == i) return false;
    }

    return true;
}

void afis(){
    for (int i = 0; i < n; i++) {
        fout << sol[i] << " ";
    }
    fout << "\n";
}

void backtrack(int k) {
    if (k == n) {
        if (check())
            afis();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (ap[i] == 0) {
            ap[i] = 1;
            sol[k] = i;
            backtrack(k + 1);
            ap[i] = 0;
        }
    }

}

int main()
{
    fin >> n;
    backtrack(0);
    return 0;
}
