#include <iostream>
using namespace std;

int a;

void mt(int aa) {
	cout << aa;
	if (aa == a) {
		return;
	}
	else {
		mt(aa + 1);
		cout << aa;
	}
}

int main() {
	cin >> a;
	mt(1);
	return 0;
}