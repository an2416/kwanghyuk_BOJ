#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = N; i > 0; i--) {
		for (int a = N - i; a > 0; a--) {
			cout << " ";
		}
		for (int b = 0; b < 2 * i - 1; b++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}