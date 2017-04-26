#include <iostream>
using namespace std;

int main() {
	int a[3][2];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
	}
	
	if (a[1][0] == a[0][0]) {
		cout << a[2][0] << " ";
	}
	else if (a[1][0] == a[2][0]) {
		cout << a[0][0] << " ";
	}
	else if (a[0][0] == a[2][0]) {
		cout << a[1][0] << " ";
	}

	if (a[0][1] == a[1][1]) {
		cout << a[2][1] << endl;
	}
	else if (a[1][1] == a[2][1]) {
		cout << a[0][1] << endl;
	}
	else if (a[0][1] == a[2][1]) {
		cout << a[1][1] << endl;
	}

	return 0;
}