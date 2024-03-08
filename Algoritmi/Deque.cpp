///100 DE PUNCTE
#include <fstream>
#include <deque>

typedef long long LL;

using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

deque <int> D;
LL rez;
int n, k;
int vec[5000002];

void citire(){
    for (int i = 0; i < n; i++)
        fin >> vec[i];
}

void solve(){
    for (int i = 0; i <= n; i++) {
        if (i >= k && !D.empty())
            rez += vec[D.front()];

        if (!D.empty()){
            if (D.front() + k <= i) {
                    D.pop_front();
            }

            while (!D.empty() && vec[i] < vec[D.back()])
                D.pop_back();

            D.push_back(i);
        }
        else
            D.push_front(i);
    }

    fout << rez;
}

int main()
{
    fin >> n >> k;
    citire();
    solve();
    return 0;
}
