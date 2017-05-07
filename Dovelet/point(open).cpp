#include <iostream>
using namespace std;

int cal(int x, int y) {
	if (x == 0) {
		if (y > 0) {
			return y;
		}
		else {
			return -y;
		}
	}
	if (x < 0) {
		x = -1 * x;
	}
	if (y < 0) {
		y = -1 * y;
	}
	while (1) {
		if (x == 0) {
			 break;
		}
		if (y > x) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		x %= y;
	}
	return y;
}

int main() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << cal(x1 - x2, y1 - y2)+1 << endl;
	return 0;
}