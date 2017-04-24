#include <iostream>
using namespace std;


// 65~70  A~F

int main() {
	char a[7];
	cin >> a;
	int add = 0,sum=0;
	while (1) {
		if (a[add] == '\0' || a[add] == NULL) {
			break;
		}
		add++;
	}

	for (int i = 0; i < add; i++) {
		int gop = 1;
		for (int z = add - i-1; z > 0; z--) {
			gop *= 16;
		}
		if ((int)a[i] >= 65) {
			sum += ((int)a[i] - 55)*gop;
		}
		else if ((int)a[i] >= 48) {
			sum += ((int)a[i] - 48)*gop;
		}
	}
	cout << sum << endl;
	return 0;
}