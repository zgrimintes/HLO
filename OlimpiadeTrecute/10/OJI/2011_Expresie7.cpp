///REZOLVARE DE (TEORETIC) 100 DE PUNCTE
#include <fstream>
#include <cstring>
#include <stack>
#include <limits.h>
#include <algorithm>

using namespace std;

ifstream fin("expresie7.in");
ofstream fout("expresie7.out");

stack <int> p;
stack <int> nr;
char E[100001];
int sir[100001];
int cnt_nr, pos, ind_s = 0, sum_fin;

int getNb() {
	int nb = 0;
	bool negative = false;

	if (E[pos] == '-') {
		pos++;
		negative = true;
	}

	for (; E[pos] >= '0' && E[pos] <= '9'; pos++)
		nb = nb * 10 + E[pos] - '0';

	return negative ? 0 - nb : nb;
}

int getMaxSir() {
	int max_sum = INT_MIN, sum_temp = 0;

	for (int i = 0; i < ind_s; i++) {
		sum_temp += sir[i];
		if (sum_temp > max_sum) max_sum = sum_temp;
		if (sum_temp < 0) sum_temp = 0;
	}

	ind_s = 0;

	return max_sum;
}

void getRes() {
	int a = nr.top();
	nr.pop();

	if (nr.empty()) {
		sum_fin = a;
		return;
	}

	int b = nr.top();
	nr.pop();

	nr.push(a + b);
}

void eval(int l) {
	while (pos <= l) {
		switch (E[pos])
		{
		case '(':
			p.push(E[pos++]);
			break;
		case '[':
			p.push(E[pos++]);
			break;
		case ')':
			while (p.top() != '(') {
				sir[ind_s++] = nr.top();
				nr.pop();
				p.pop();
			}
			sir[ind_s++] = nr.top();
			nr.pop();

			nr.push(getMaxSir());

			p.pop();
			pos++;
			break;
		case ']':
			while (p.top() != '[') {
				sir[ind_s++] = nr.top();
				nr.pop();
				p.pop();
			}
			sir[ind_s++] = nr.top();
			nr.pop();

			nth_element(sir, sir + (ind_s) / 2, sir + ind_s);
			nr.push(sir[(ind_s - 1) / 2]);

			p.pop();
			ind_s = 0;
			pos++;
			break;
		case ',':
			p.push(E[pos++]);
			break;
		default:
			nr.push(getNb());
			cnt_nr++;
			break;
		}
	}

	while (!nr.empty()) {
		getRes();
	}
}

int main() {
	fin.getline(E, 100001);
	eval(strlen(E) - 1);

	fout << cnt_nr << " \n" << sum_fin;

	return 0;
}
