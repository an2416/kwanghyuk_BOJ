#include <iostream>
using namespace std;

int cnt = 0, stair;

void cal(int a) {
	if (a > stair) {
		return;
	}
	if (a == stair) {
		cnt++;
	}
	else {
		cal(a + 1);
		cal(a + 2);
	}
}

int main() {
	cin >> stair;
	cal(0);
	cout << cnt;
	return 0;
}