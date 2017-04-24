#include <iostream>
using namespace std;

int uclid(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return uclid(b, a%b);
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int a, b;
		cin >> a >> b;
		cout << a*b/uclid(a, b) << endl;
	}
	return 0;
}