#include <iostream>
using namespace std;

long long uclid(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		uclid(b, a%b);
	}
}

int main() {
	long long a, b,tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> a >> b;
		cout << a*b/uclid(a, b) << endl;
	}
	return 0;
}