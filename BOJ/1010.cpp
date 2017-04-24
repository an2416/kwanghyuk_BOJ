#include <iostream>
using namespace std;

int result[31][31];


// 메모이제이션
void arr_init() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			result[i][j] = 0;
		}
	}
}

int combi(int a, int b) {
	if (a == b || b == 0) {
		return 1;
	}
	if (result[a][b] != 0) {
		return result[a][b];
	}
	else {
		result[a][b] = combi(a - 1, b - 1) + combi(a - 1, b);
		return result[a][b];
	}
}

int main() {
	int a, b,tc,result=0;
	arr_init();
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> a >> b;
		cout << combi(b, a) << endl;
	}
	return 0;
}