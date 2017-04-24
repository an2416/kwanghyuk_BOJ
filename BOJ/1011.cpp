#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		long long x, y;
		cin >> x >> y;
		long long dis = y - x;
		long long k = 0;
		for (long long i = 1;; i++) {
			k += i;
			if (dis <= k) {
				cout << 2 * i - 1 << endl; // È¦¼ö ¹øÂ°
				break;
			}
			k += i;
			if (dis <= k) {
				cout << 2 * i << endl; // Â¦¼ö ¹øÂ°
				break;
			}
		}
	}
	return 0;
}