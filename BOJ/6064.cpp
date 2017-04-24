#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		if (M < N) {
			int tmp = M;
			M = N;
			N = tmp;
			tmp = x;
			x = y;
			y = tmp;
		}
		int result = -1;
		for (int j = 0; j < N; j++) {
			if ((j*M + x-1) % N+1 == y) {
				result = j*M + x;
				break;
			}
		}
		cout << result << endl;
	}
	return 0;
}