#include <iostream>
using namespace std;

int height;

void mt(int a) {
	if (a <= 0) {
		return;
	}
	else {
		mt(a - 1);
		cout << a;
		mt(a - 1);
	}
}

int main() {
	cin >> height;
	mt(height);
	return 0;
}