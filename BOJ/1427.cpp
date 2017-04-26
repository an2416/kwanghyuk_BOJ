#include <iostream>
using namespace std;

int main() {
	char input[11];
	cin >> input;
	int add = 0;

	while (1) {
		if (input[add] == '\0' && input[add] == NULL) {
			break;
		}
		add++;
	}

	for (int i = 0; i < add-1; i++) {
		for (int j = i + 1; j < add; j++) {
			if (input[i] < input[j]) {
				int tmp = input[j];
				input[j] = input[i];
				input[i] = tmp;
			}
		}
	}


	for (int i = 0; i < add; i++) {
		cout << input[i];
	}
	return 0;
}