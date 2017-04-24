#include <iostream>
using namespace std;

int main() {
	// 97
	char word[105];
	cin >> word;
	int add = 0;
	

	int word_cnt = 0;
	while (1) {
		if (word[add] == '\0' || word[add] == NULL) {
			break;
		}

		else if (word[add] == 'c' && word[add + 1] == '=') {
			word_cnt++;
			add+=2;
		}
		else if (word[add] == 'c' && word[add + 1] == '-') {
			word_cnt++;
			add += 2;
		}
		else if (word[add] == 'd' && word[add + 1] == 'z' && word[add + 2] == '=') {
			word_cnt++;
			add += 3;
		}
		else if (word[add] == 'd' && word[add + 1] == '-') {
			word_cnt++;
			add += 2;
		}
		else if (word[add] == 'l' && word[add + 1] == 'j') {
			word_cnt++;
			add += 2;
		}
		else if (word[add] == 'n' && word[add + 1] == 'j') {
			word_cnt++;
			add += 2;
		}
		else if (word[add] == 's' && word[add + 1] == '=') {
			word_cnt++;
			add += 2;
		}
		else if (word[add] == 'z' && word[add + 1] == '=') {
			word_cnt++;
			add += 2;
		}
		
		else {
			word_cnt++;
			add += 1;
		}
	}

	cout << word_cnt << endl;
	return 0;
}