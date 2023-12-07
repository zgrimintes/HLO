//REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <cstring>

using namespace std;

char cuv1[200][200], cuv2[200][200], _cuv_Alph[200][200];
int max_cuv = 0;

void lower(char* c) {
	for (int i = 0; i < strlen(c); i++)
		c[i] = tolower(c[i]);

}

void splitIntoWords(char* c, char cs[][200]) {
	char* temp = strtok(c, " ");
	int ind = 0, cuv_temp = 0;

	do {
		lower(temp);
		strcpy(cs[ind++], temp);
		temp = strtok(NULL, " ");
		cuv_temp++;
	} while (temp);

	if (max_cuv < cuv_temp) max_cuv = cuv_temp;
}

void removeAllLike(char c[][200], int n) {
	for (int i = 0; i < n; i++) {
		if (c[i][0] == NULL) continue;

		for (int j = i + 1; j < n; j++) {
			if (strcmp(c[i], c[j]) != 0) continue;

			for (int l = 0; l < strlen(c[j]); l++) 
				c[j][l] = NULL;
		}
	}
}

void orderAlphabetical(char c[][200], int n) {
	int ind = 0;
	for (int i = 0; i < n; i++) {
		int indx_min = i;
		char cuv_temp[200] = { 0 }; for (int l = 0; l < strlen(c[i]); l++) cuv_temp[l] = c[i][l];

		for (int j = i; j < n; j++) {	
			if (strcmp(cuv_temp, c[j]) > 0) {
				indx_min = j;
				for (int l = 0; l < max(strlen(c[j]), strlen(cuv_temp)); l++) 
					cuv_temp[l] = c[j][l];
			}
		}

		if (indx_min != i) {
			swap(c[i], c[indx_min]);
		}

		strcpy(_cuv_Alph[ind++], cuv_temp);
	}
}

void workStrings(char *c1, char *c2) {
	splitIntoWords(c1, cuv1);
	splitIntoWords(c2, cuv2);
	
	removeAllLike(cuv1, max_cuv);
	removeAllLike(cuv2, max_cuv);

	orderAlphabetical(cuv1, max_cuv);
}

void findAlike() {
	for (int i = 0; i < max_cuv; i++) {
		if (strcmp(_cuv_Alph[i], "") == 0) continue;
		for (int j = 0; j < max_cuv; j++) {
			if (!strcmp(_cuv_Alph[i], cuv2[j]))
				cout << _cuv_Alph[i] << "\n";
		}
	}
}

int main() {
	char c1[255], c2[255];
	cin.getline(c1, 255);
	cin.getline(c2, 255);

	workStrings(c1, c2);

	findAlike();

	return 0;
}
