#include <iostream>
using namespace std;

int main() {
	char gr[51];
	int l = 0,gr_add=0, status=0;
	cin >> gr;

	if (gr[0] == ')') {
		status = 1;
		l += 10;
	}
	else {
		status = 0;
		l += 10;
	}
	gr_add++;

	while (1) {
		if (gr[gr_add] == '\0' || gr[gr_add] == NULL) {
			break;
		}
		if (status == 1 && gr[gr_add] == ')') {
			l += 5;
		}
		else if (status == 1 && gr[gr_add] == '(') {
			status = 0;
			l += 10;
		}
		else if (status == 0 && gr[gr_add] == '(') {
			l += 5;
		}
		else if (status == 0 && gr[gr_add] == ')') {
			status = 1;
			l += 10;
		}

		gr_add++;
	}
	cout << l << endl;
	return 0;
}