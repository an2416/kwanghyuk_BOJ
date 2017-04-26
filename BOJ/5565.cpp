#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	for (int i = 0; i < 9; i++) {
		int b;
		cin >> b;
		a -= b;
	}
	cout << a;
	return 0;
}