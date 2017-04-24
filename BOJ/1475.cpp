#include <iostream>
using namespace std;

int main() {
	char n[1000001];
	int chk[10];
	cin >> n;
	int add = 0;

	for (int i = 0; i < 10; i++) {
		chk[i] = 0;
	}

	while (1) {
		if (n[add] == '\0' || n[add] == NULL) {
			break;
		}
		chk[n[add] - '0']++;
		add++;
	}

	chk[9] = (chk[6] + chk[9]) / 2 + (chk[6] + chk[9]) % 2;
	chk[6] = 0;
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (chk[i] > max) {
			max = chk[i];
		}
	}
	cout << max <<endl;

	return 0;
}