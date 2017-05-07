//#include <iostream>
//using namespace std;
//
//void binary(int a) {
//	if (a == 1 || a == 0) {
//		cout << a;
//		return;
//	}
//	binary(a / 2);
//	cout << a % 2;
//}
//
//int main() {
//	int a;
//	cin >> a;
//	binary(a);
//	return 0;
//}

#include <iostream>
using namespace std;

int main() {
	int a,binary[10000],binary_add=0;
	cin >> a;
	while (1) {
		if (a == 1 || a == 0) {
			binary[binary_add++] = a;
			break;
		}
		binary[binary_add++] = a % 2;
		a /= 2;
	}

	for (int i = binary_add-1; i >= 0; i--) {
		cout << binary[i];
	}
	return 0;
}