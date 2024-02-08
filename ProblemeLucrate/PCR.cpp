///REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <cstring>

using namespace std;

int frecv[10];
char nb[100];
int cnt_cif;

void getDigits() {
    for (int i = 0; nb[i]; i++) {
        int cif = nb[i] - '0';
        frecv[cif]++;
        cnt_cif++;
    }
}

long long fact(int n) {
    long long rez = 1;
    for (int i = 1; i <= n; i++)
        rez *= i;

    return rez;
}

long long permCuRep() {
    long long rez = 1;
    rez = fact(cnt_cif);

    for (int i = 0; i <= 9; i++)
        rez /= fact(frecv[i]);

    return rez;
}

int main()
{
    cin >> nb;
    getDigits();

    int frecv_imp = 0;
    for (int i = 0; i <= 9; i++) 
        if (frecv[i] % 2 == 1) frecv_imp++;

    if (frecv_imp > 1) cout << 0;
    else {
        for (int i = 0; i <= 9; i++)
            frecv[i] /= 2;
        cnt_cif /= 2;

        if (frecv[0] == 0) 
            cout << permCuRep();
        else {
            long long rez1 = permCuRep();

            frecv[0]--;
            
            cnt_cif -= 1;
            long long rez2 = permCuRep();

            cout << rez1 - rez2;
        }
    }

    return 0;
}
