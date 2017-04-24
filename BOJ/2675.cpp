#include <iostream>
using namespace std;

int main() {
	int testcase;
	char word[21];
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int count;
		cin >> count;
		cin >> word;
		int add=0;
		while (1) {
			if (word[add] == '\0' || word[add] == NULL) {
				break;
			}
			else {
				for (int j = 0; j < count; j++) {
					cout << word[add];
				}
			}
			add++;
		}
		cout << endl;
	}
	return 0;
}