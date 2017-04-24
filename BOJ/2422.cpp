#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int a = N - i-1; a > 0; a--) {
			cout << " ";
		}
		for (int b = 0; b < 2 * (i+1) - 1; b++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}