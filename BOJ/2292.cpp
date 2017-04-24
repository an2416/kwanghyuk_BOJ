#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	// 1 -> 6 - > 12 -> 18
	int my_num = 2;
	int min_num = 2;
	int max_num = 7;
	int cnt = 2;
	while (1) {
		if (a == 1) {
			cout << 1 << endl;
			return 0;
		}
		else if (a >= min_num && a <= max_num) {
			cout << cnt << endl;
			return 0;
		}
		else {
			min_num = max_num + 1;
			max_num += my_num * 6;
			my_num++;
			cnt++;
		}
	}
	return 0;
}