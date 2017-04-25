#include <iostream>
using namespace std;

int main() {
	int n, num[10001];
	for (int i = 0; i < 10001; i++) {
		num[i] = 0;
	}
	ios::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[a]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}