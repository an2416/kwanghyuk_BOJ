#include <iostream>
using namespace std;

int main() {
	//char music[8] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
	int a[8];
	int flag1 = 0, flag2 = 0;
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < 8; i++) {
		if (a[i - 1] + 1 == a[i]) {
			flag1++;
		}
		else if (a[i - 1] - 1 == a[i]) {
			flag2++;
		}
	}

	if (flag1 == 7) {
		cout << "ascending" << endl;
	}
	else if (flag2 == 7) {
		cout << "descending" << endl;
	}
	else {
		cout << "mixed" << endl;
	}

	return 0;
}