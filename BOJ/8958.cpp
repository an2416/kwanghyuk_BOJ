#include <iostream>
using namespace std;

int main() {
	char input[81];
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> input;
		int add = 0;
		int score = 0;
		int score_tmp = 0;
		while (1) {
			if (input[add] == 'O') {
				score_tmp++;
				score += score_tmp;
			}
			else if (input[add] == 'X') {
				score_tmp = 0;
			}
			else if (input[add] == '\0' || input[add] == NULL) {
				score_tmp = 0;
				break;
			}
			add++;
		}
		cout << score << endl;
	}
	return 0;
}