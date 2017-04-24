#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		if (n%h == 0) {
			if ((n / h) >= 10) {
				cout << h << (n / h) << endl;
			}
			else {
				cout << h << "0" << (n / h) << endl;
			}
		}
		else {
			if ((n / h + 1) >= 10) {
				cout << n%h << (n / h) + 1 << endl;
			}
			else {
				cout << n%h << "0" << (n / h) + 1 << endl;
			}
		}
	}
	return 0;
}