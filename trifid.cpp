//DE CONTINUAT
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("trifid.in");
ofstream fout("trifid.out");

int c;
char mat[3][3][3];
char mesaj[10000];
int* rep;

void citire() {
	int indxc = 0;
	int indxl = 0;
	char c;

	while (indxl < 3|| indxc != 9) {
		if (indxc < 3) {
			fin >> c;
			mat[indxl][indxc++][0] = c;
		}
		else if (indxc < 6) {
			fin >> c;
			mat[indxl][indxc++ % 3][1] = c;
		}
		else if (indxc < 9) {
			fin >> c;
			mat[indxl][indxc++ % 3][2] = c;
		}
		else {
			if (++indxl < 3) {
				fin >> c;
				mat[indxl][0][0] = c;
			}
			else
				continue;
			indxc = 1;
		}
	}
}

int main() {
	fin >> c;
	citire();
	fin.getline(mesaj, 10000);

	cout << mesaj;
	return 0;
}
