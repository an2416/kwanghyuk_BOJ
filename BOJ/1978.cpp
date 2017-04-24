#include <iostream>
using namespace std;

bool find(int a) {
	int num = 0;
	for (int i = 1; i <= a; i++) {
		if (a%i == 0) {
			num++;
		}
		if (num == 3) {
			return false;
		}
	}
	if (num == 2) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int N,a,cnt=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		bool result = find(a);
		if (result) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}