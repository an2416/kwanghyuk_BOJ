#include <iostream>
using namespace std;

int pow(int x, int y) {
	if (y == 0) {
		return 1;
	}
	if (y > 0) {
		return x * pow(x, y - 1);
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << pow(a, b);
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a, b, result=1;
//	cin >> a >> b;
//	for (int i = 0; i < b; i++) {
//		result *= a;
//	}
//	cout << result;
//	return 0;
//}