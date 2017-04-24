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
	int a, b, c, d;
	int up, down;
	cin >> a >> b >> c >> d;

	up = (b*c) + (a*d);
	down = b*d;

	int moc = uclid(up, down);
	cout << up/moc << " " << down/moc << endl;
	return 0;
}