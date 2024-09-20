#include <iostream>

using namespace std;

void b16_rec(unsigned int n) {
    if (!n) return;

    unsigned int rt = n % 16;
    unsigned int ct = n / 16;

    b16_rec(ct);

    if (rt < 10) cout << rt;
    else cout << (char)(55 + rt);

}

int main()
{
    b16_rec(16712523);
    return 0;
}
