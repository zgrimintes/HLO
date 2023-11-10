//Problema de pe infoarena

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");

void inm_mat(int a[2][2], int b[2][2], int rsl[2][2]) {

    rsl[0][0] = a[0][0] * b[0][0] + a[0][1]*b[1][0];
    rsl[0][1] = a[0][0] * b[0][1] + a[0][1]*b[1][1];
    rsl[1][0] = a[1][0] * b[0][0] + a[1][1]*b[1][0];
    rsl[1][1] = a[1][0] * b[0][1] + a[1][1]*b[1][1];
}

void copiere(int ans[2][2], int temp[2][2]) {
    ans[0][0] = temp[0][0];
    ans[0][1] = temp[0][1];
    ans[1][0] = temp[1][0];
    ans[1][1] = temp[1][1];
}

void ridicare(int A[2][2], int n) { // Ridicare la putere in timp logaritmic pentru eficienta
    int ans[2][2] = {1, 0, 0, 1};

    while (n) {

        if (n % 2 == 1){

            inm_mat(A, ans, temp);
            copiere(ans, temp);
        }

        inm_mat(A, A, temp);
        copiere(A, temp);

        n /= 2;
    }
    copiere(A, ans); // Copiez in mat A(matricia principala) valoarea lui ans(care e rezultatul exponentierii rapide)
}


int main()
{
    int k;
    ///int A = {{0, 1}, {1, 1}};
    int A[2][2] = {{0, 1}, {1, 1}};
    fin >> k;
  
    ridicare(A, k);
    cout << A[0][1] + A[0][0]; //Afisez termenul din matricia rezultata din inmultirea la cazurile de baza din sirul lui fibonacci cu matricia {{0, 1}, {1, 1}}
  
    return 0;
}
