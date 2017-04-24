#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			cout << " ";
		}
		for (int k = 0; k < i + 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << " ";
		}
		for (int k = i + 1; k < N; k++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}