///100 DE PUNCTE
#include <fstream>
#include <deque>

#define MAX -300001

using namespace std;

ifstream fin("secventa.in");
ofstream fout("secventa.out");

deque <int> D;
int vec[500001];
int n, k;
int s, f, v_max = MAX;

void citire(){
    for (int i = 0; i < n; i++)
        fin >> vec[i];
}

void solve(){
    for (int i = 0; i <= n; i++){
        if (i >= k && !D.empty()){
            if (vec[D.front()] > v_max){
                v_max = vec[D.front()];
                s = i - k + 1;
                f = i ;
            }
        }

        if (!D.empty()){
            if (D.front() + k <= i){
                D.pop_front();
            }

            while (!D.empty() && vec[i] < vec[D.back()])
                D.pop_back();

            D.push_back(i);
        }
        else D.push_back(i);
    }
}

int main(){
    fin >> n >> k;
    citire();
    solve();
    fout << s << " " << f << " " << v_max;
    return 0;
}
