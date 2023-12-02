//REZOLVARE DE 0 PUNCTE
#include <iostream>
#include <cstring>

using namespace std;

char secv[100000];
int cnt = 0, cnt_ast = 0, sum5 = 0;

void check_char(char c) {
	switch (c)
	{
	case '*':
		cnt_ast++;
		break;
	case '.':
		break;
	default:
		sum5 += c;
		break;
	}
}

void num_subsecv(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		sum5 = cnt_ast = 0;

		for (int j = i; j < i + 5; j++) {
			check_char(s[j]);
		}

		if (sum5 == 8) cnt++;
		else if (cnt_ast != 0) {
			if (sum5 == 0) {
				if (cnt_ast == 5) cnt++;
				else continue;
			}
			else
				if ((8 - sum5) <= cnt_ast * 2) cnt++;

		}
	}
}

void clean_string(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		if (isalpha(s[i]))
			s[i] = tolower(s[i]);
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == '-') s[i] = 2;
		else if (s[i] == 'b' || s[i] == 'd' || s[i] == '+') s[i] = 1;
		else if (s[i] != '*') s[i] = '.';
	}
}

int main() {
	cin.getline(secv, 100000);
	clean_string(secv);
	num_subsecv(secv);

	cout << cnt;
	return 0;
}
