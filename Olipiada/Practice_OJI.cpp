///10 PUNCTE
#include <fstream>
#include <map>
#include <deque>

using namespace std;

ifstream fin("3secv.in");
ofstream fout("3secv.out");

map <int, int> M;
deque <int> D;
int t, n, ai;
int cnt_secv, max_secv, first;

void get_secv(int ind) {
	map<int, int>::iterator it = M.begin();

	while (it != M.end()) {
		if (D.front() == it->first) first = it->first;

		if (ind != it->first) cnt_secv += it->second;
		it++;
	}

	if (max_secv < cnt_secv) max_secv = cnt_secv;
}

void empty_stl() {
	M.clear();
	D.clear();
}

void solve_query() {
	for (int i = 0; i < n; i++){
		fin >> ai;
		M[ai]++;
		D.push_back(ai);

		if (M.size() > 3) {
			get_secv(ai);
			M.erase(first);
			D.pop_front();
		}

		cnt_secv = 0;
	}

	if (!max_secv) get_secv(-1);

	empty_stl();
}

void solve() {
	while (t) {
		fin >> n;
		solve_query();
		fout << max_secv << "\n";
		max_secv = 0;
		t--;
	}
}

int main() {
	fin >> t;
	solve();
	return 0;
}
