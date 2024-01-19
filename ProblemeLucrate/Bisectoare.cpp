#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bisectoare.in");
ofstream fout("bisectoare.out");

int main() {
	int disj = 0;
	int x;

	while (fin >> x) {
		disj = disj ^ x;
	}

	fout << disj;

	return 0;
}
