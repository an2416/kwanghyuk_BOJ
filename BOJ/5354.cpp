#include <iostream>
using namespace std;

int main() {
	int tc, n;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		cin >> n;
		if (n == 1) {
			cout << "#";
			if (t != tc - 1) {
				cout << '\n' << '\n';
			}
			continue;
		}
		for (int i = 0; i < n; i++) {
			cout << "#";
		}
		cout << '\n';

		for (int j = 0; j < n - 2; j++) {
			cout << "#";
			for (int i = 0; i < n - 2; i++) {
				cout << "J";
			}
			cout << "#" << '\n';
		}

		for (int i = 0; i < n; i++) {
			cout << "#";
		}
		if (t != tc - 1) {
			cout << '\n' << '\n';
		}
	}

	return 0;
}