#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("cifre_romane2.in");
ofstream fout("cifre_romane2.out");

int c;
int nr;
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

void init() {
    
}

int main()
{
    fin >> c >> nr;
    init();

    if (c == 1) {
        solve1();
    }

    return 0;
}
