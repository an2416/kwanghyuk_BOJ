#include <iostream>
using namespace std;

int main() {
	int tc;
	
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int add = 0;
		int compare = 0;
		char input[51];
		cin >> input;

		while (1) {
			if (input[add] == '\0' || input[add] == NULL) {
				if (compare == 0) {
					cout << "YES" << '\n';
				}
				else {
					cout << "NO" << '\n';
				}
				break;
			}

			if (input[add] == '(') {
				compare += 1;
			}
			else if (input[add] == ')') {
				if (compare <= 0) {
					cout << "NO" << '\n';
					break;
				}
				else {
					compare -= 1;
				}
			}
			add++;
		}

	}
	return 0;
}