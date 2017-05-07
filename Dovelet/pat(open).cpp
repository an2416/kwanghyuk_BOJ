#include <iostream>
using namespace std;

// n중 포문
// n개중 k개를 1로
// 중복X

int tmp[50],n,k;

void init(int a) {
	for (int i = 0; i < a; i++) {
		tmp[i] = 0;
	}
}

void pat(int start, int end, int num) { // for문 시작, 종료, n중 포문의 n 입력
	if (num <= 0) {
		return;
	}
	else {
		for (int i = start; i < end; i++) {
			tmp[i] = 1;
			pat(i+1, end+1, num - 1);
			if (end == n) {   // 재귀로 for문을 만들면서 n중 포문의 n번째 포문에서만 동작하도록 설정
				for (int j = 0; j < n; j++) {
					cout << tmp[j];
				}
				cout << endl;
			}
			tmp[i] = 0;  // 하나를 선택하여 출력했으면 다시 원상복구
		}
	}
}

int main() {
	cin >> n >> k;
	init(n);
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			cout << "0";
		}
		return 0;
	}
	pat(0,n-k+1,k);
	return 0;
}