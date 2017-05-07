//#include <iostream>
//using namespace std;
//
//int uclid(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	else {
//		return uclid(b, a%b);
//	}
//}
//
//int main() {
//	int a, b;
//	cin >> a >> b;
//	int result = uclid(a, b);
//	cout << result << " " << (long long)a*b / result;
//	return 0;
//}

#include <iostream>
using namespace std;

int main() {
	int a, b, tmp_a, tmp_b;
	cin >> a >> b;
	tmp_a = a;
	tmp_b = b;
	while (1) {
		if (tmp_b == 0) {
			break;
		}
		else {
			int tmp = tmp_a;
			tmp_a = tmp_b;
			tmp_b = tmp%tmp_b;
		}
	}
	cout << tmp_a << " " << (long long)a*b/tmp_a;
	return 0;
}