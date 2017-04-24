#include <iostream>
using namespace std;

int main() {
	//65~122
	//a-z  97~122    A-Z  65~90
	char word[1000001];
	int chk[26];
	cin >> word;
	
	int add = 0;

	for (int i = 0; i < 26; i++) {
		chk[i] = 0;
	}

	while (1) {
		if (word[add] == '\0' || word[add] == NULL) {
			break;
		}
		else {
			if ((int)word[add] >= 97) {
				chk[(int)word[add] - 97]++;
			}
			else {
				chk[(int)word[add]-65]++;
			}
		}
		add++;
	}
	int Max = 0;
	int Max_add = 0;
	for (int i = 0; i < 26; i++) {
		if (Max < chk[i]) {
			Max = chk[i];
			Max_add = i;
		}
	}
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (Max == chk[i]) {
			flag++;
		}
		if (flag == 2) {
			cout << '?' << endl;
			return 0;
		}
	}
	
	cout << (char)(Max_add + 65) << endl;
	return 0;
}