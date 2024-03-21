///100 PUNCTE
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("cifre_romane2.in");
ofstream fout("cifre_romane2.out");

int c;
int nr;
char nrR[10001];
char cif[10][10][20] =  { { "" , "(M)", "(M)(M)", "(M)(M)(M)" },
                        { "" , "(C)", "(C)(C)", "(C)(C)(C)", "(C)(D)", "(D)", "(D)(C)", "(D)(C)(C)", "(D)(C)(C)(C)", "(C)(M)" },
                        { "" , "(X)", "(X)(X)", "(X)(X)(X)", "(X)(L)", "(L)", "(L)(X)", "(L)(X)(X)", "(L)(X)(X)(X)", "(X)(C)" },
                        { "" , "M", "MM", "MMM", "M(V)", "(V)", "(V)M", "(V)MM", "(V)MMM", "M(X)" },
                        { "" , "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
                        { "" , "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
                        { "" , "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }
                        };

void solve1() {
    int a = nr / 1000000;
    int p10 = 1000000;

    for (int i = 0; i < 8; i++) {
        fout << cif[i][a];
        p10 /= 10; if (!p10) p10++;
        a = nr / p10 % 10;
    }
}

void solve2() {
    int ans = 0;
    int j = 3, p10 = 1000000;
    for (int i = 0; i < 8; i++) {
        for (; j > 0; j--) {
            char* p = strstr(nrR, cif[i][j]);
            if (p == nrR) {
                strcpy(nrR, nrR + strlen(cif[i][j]));
                ans += p10 * j;
                break;
            }
        }

        p10 /= 10;
        j = 9;
    }

    if (strlen(nrR)) {
        fout << "Numar invalid";
        return;
    }

    fout << ans;
}

int main()
{
    fin >> c;

    if (c == 1) {
        fin >> nr;
        solve1();
    }
    else {
        fin.get();
        fin.getline(nrR, 10001);
        solve2();
    }

    return 0;
}
