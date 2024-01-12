#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("triunghiul.in");
ofstream fout("triunghiul.out");

int triPasc[105][105];
int n;

void afisare(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= i; j++)
            cout << triPasc[i][j] << " ";
        cout << "\n";
    }
}

void afisareL(int l){

    for (int j = 0; j <= l; j++)
        fout << triPasc[l][j] << " ";

}


void formareTriunghi(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            triPasc[i][j] = triPasc[i - 1][j] + triPasc[i - 1][j - 1];
        }
    }
}

int main()
{

    fin >> n;

    for (int i = 0; i <= n; i++) {
        triPasc[i][i] = 1;
        triPasc[i][0] = 1;
    }

    formareTriunghi();
    afisareL(n);
    //afisare();
}
