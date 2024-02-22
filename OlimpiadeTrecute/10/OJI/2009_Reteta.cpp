///DE TERMINAT
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

ifstream fin("reteta.in");
ofstream fout("reteta.out");

map <string, int> M;
char ret[1001];
int min_ret;

int getNb(int i) {
	int nb = 0;
	for (; ret[i] >= '0' && ret[i] <= '9'; i++) {
		nb = nb * 10 + ret[i] - '0';
	}

	return nb;
}

void getIngredient(int i) {
	char ing[21] = "";
	while (ret[i] != ' ') {
		
		i++;
	}

	while (ret[i] == ' ') i++;

	M[ing] += getNb(i);
}

void afisare_map() {
	map<string, int>::iterator it = M.begin();

	while (it != M.end()) {
		fout << it->first << " " << it->second << "\n";
	}
}

int main() {
	fin.getline(ret, 1001);
	
	for (int i = 0; ret[i]; i++) {
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


	fout << min_ret << "\n";
	afisare_map();
	return 0;
}
