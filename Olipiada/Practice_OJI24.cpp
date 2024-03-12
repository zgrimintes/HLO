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
	bool verified = false;

	for (int i = 0; i < n; i++){
		verified = false;
		fin >> ai;
		M[ai]++;
		D.push_back(ai);

		if (M.size() > 3) {
			get_secv(ai);
			M.erase(first); ///Problema apare aici cand tu stergi toate instantele unui numar chiar daca inca poate face parte din sir.
					///ex: 1 1 4 4 7 2 4 4 1 2 2 1; o sa ajunga D-ul sa arate asa: 4 4 7 2 4 4, iar cand vine 1 o sa se schimbe in
					/// 7 2 4 4 1 care e corect deoarece 7 ar trebui sa dispara si sa ramanem cu 2 4 4... 
					///Pacat ca in map se sterg complet instantele lui 4. De aceea aleg sa sterg doar aparitile in fata deque-ului, 
					///iar daca in map valoarea salvata nr respectiv ajunge <= 0, doar atunci il sterg de tot.
			int f = D.front();
			while (D.front() == f) D.pop_front(); 
			verified = true;
		}

		cnt_secv = 0;
	}

	if (!verified) get_secv(-1);

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
