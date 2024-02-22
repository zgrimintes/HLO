///REZOLVARE DE 100 DE PUNCTE
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

ifstream fin("reteta.in");
ofstream fout("reteta.out");

map <string, int> M;
char ret[1001];
int min_ret;

int getNb(int &i) {
	int nb = 0;
	for (; ret[i] >= '0' && ret[i] <= '9'; i++) {
		nb = nb * 10 + ret[i] - '0';
	}

	return nb;
}

void getIngredient(int &i) {
	char ing[21] = "";
	int ind_i = 0;
	while (ret[i] != ' ') {
		ing[ind_i++] = ret[i];
		i++;
	}

	while (ret[i] == ' ') i++;

	M[ing] += getNb(i);
}

void afisare_map() {
	map<string, int>::iterator it = M.begin();

	while (it != M.end()) {
		fout << it->first << " " << it->second << "\n";
		it++;
	}
}

void solve() {
	for (int i = 0; ret[i];) {
		switch (ret[i]) {
		case ')':
			i++;
			while (ret[i] == ' ') i++;
			min_ret += getNb(i);
			break;
		case '(':
		case ' ':
			i++;
			break;
		default:
			getIngredient(i);
			break;
		}

	}
}

int main() {
	fin.getline(ret, 1001);
	solve();

	fout << min_ret << "\n";
	afisare_map();
	return 0;
}
