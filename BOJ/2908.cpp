#include <iostream>
using namespace std;

int main() {
	char a[4], b[4];
	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		if (a[i] > b[i]) {
			cout << a[2] << a[1] << a[0] << endl;
			return 0;
		}
		else if (a[i] < b[i]) {
			cout << b[2] << b[1] << b[0] << endl;
			return 0;
		}
	}
	return 0;
}