#include <iostream>
using namespace std;

int main() {
	int num[10],tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		for (int i = 0; i < 10; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 10; j++) {
				if (num[i] < num[j]) {
					int tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
				}
			}
		}
		cout << num[2] << '\n';

	}

	return 0;
}