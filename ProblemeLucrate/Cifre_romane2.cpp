///C1
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("cifre_romane2.in");
ofstream fout("cifre_romane2.out");

int c;
int nr;
char mln[4][20] = {"" , "(M)", "(M)(M)", "(M)(M)(M)"};
char smii[10][20] = {"" , "(C)", "(C)(C)", "(C)(C)(C)", "(C)(D)", "(D)", "(D)(C)", "(D)(C)(C)", "(D)(C)(C)(C)", "(C)(M)"};
char zmii[10][20] = {"" , "(X)", "(X)(X)", "(X)(X)(X)", "(X)(L)", "(L)", "(L)(X)", "(L)(X)(X)", "(L)(X)(X)(X)", "(X)(C)"};
char mii[10][20] = {"" , "M", "MM", "MMM", "M(V)", "(V)", "(V)M", "(V)MM", "(V)MMM", "M(X)"};
char sute[10][20] = {"" , "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char zeci[10][20] = {"" , "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char unit[10][20] = {"" , "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

void solve1(){
    int a = nr / 1000000;
    int b = nr / 100000 % 10;
    int c = nr / 10000 % 10;
    int d = nr / 1000 % 10;
    int e = nr / 100 % 10;
    int f = nr / 10 % 10;
    int g = nr % 10;

    fout << mln[a] << smii[b] << zmii[c] << mii[d] << sute[e] << zeci[f] << unit[g];
}

int main()
{
    fin >> c >> nr;

    if (c == 1){
        solve1();
    }

    return 0;
}
