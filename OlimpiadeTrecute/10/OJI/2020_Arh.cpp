///EXEMPLU CORECT
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;

ifstream fin("arh.in");
ofstream fout("arh.out");

stack <char> smn, par, lit;
char arh[10001], rez[100001];
int p, cnt_op;
char temp[100];
int ind_temp = 0;

void makePalindrom() {
	if (smn.top() == '*') {
		for (int j = ind_temp - 1; j >= 0; j--) {
			lit.push(temp[j]);
			par.push('.');
		}
		for (int j = 0; j < ind_temp; j++) {
			lit.push(temp[j]);
			par.push('.');
		}
	}
	else {
		for (int j = ind_temp - 1; j >= 0; j--) {
			lit.push(temp[j]);
			par.push('.');
		}
		for (int j = 1; j < ind_temp; j++) {
			lit.push(temp[j]);
			par.push('.');
		}
	}
}

void concatenations() {
	for (int i = smn.top() - '0'; i > 0; i--) {
		for (int j = ind_temp - 1; j >= 0; j--)
		{
			lit.push(temp[j]);
			par.push('.');
		}
	}
}

void pushDefault() {
	if (arh[p] >= '0' && arh[p] <= '9') smn.push(arh[p]);
	else {
		lit.push(arh[p]);
		par.push('.');
	}
}

void closeBracket() {
	cnt_op++;
	ind_temp = 0;
	while (par.top() != '(') {
		par.pop();
		temp[ind_temp++] = lit.top();
		lit.pop();
	}
	par.pop();
	concatenations();
}

void closeSqrBracket() {
	cnt_op++;
	ind_temp = 0;
	while (par.top() != '[') {
		par.pop();
		temp[ind_temp++] = lit.top();
		lit.pop();
	}
	par.pop();
	makePalindrom();
}

void solve() {
	int len = strlen(arh);
	while (p < len) {
		switch (arh[p])
		{
		case '(':
			par.push(arh[p++]);
			break;
		case '[':
			par.push(arh[p++]);
			break;
		case ')':
			closeBracket();
			smn.pop();
			p++;
			break;
		case ']':
			closeSqrBracket();
			smn.pop();
			p++;
			break;
		case '*':
			if (arh[p - 1] == '[') smn.push(arh[p]);
			else smn.push(arh['+']);
			p++;
			break;
		default:
			pushDefault();
			p++;
			break;
		}
	}
}

void afisare() {
	int ind_rez = lit.size() - 1;
	while (!lit.empty()) {
		rez[ind_rez--] = lit.top();
		lit.pop();
	}

	fout << rez;
}

int main() {
	fin.getline(arh, 10001);
	solve();
	fout << cnt_op << "\n";
	afisare();
	return 0;
}
