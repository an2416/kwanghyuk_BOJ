#include <iostream>
using namespace std;

int tmp_12[10], cnt_12=0;
int tmp_16[10], cnt_16 = 0;

void make_12(int a, int b) {
	if (a < 12) {
		tmp_12[b] = a;
		cnt_12 = b;
		return;
	}
	tmp_12[b] = a % 12;
	make_12(a / 12, b + 1);
}

void make_16(int a, int b) {
	if (a < 16) {
		tmp_16[b] = a;
		cnt_16 = b;
		return;
	}
	tmp_16[b] = a % 16;
	make_16(a / 16, b + 1);
}

void cal(int a) {
	int cal_10 = a / 1000 + a % 1000 / 100 + a % 1000 % 100 / 10 + a % 1000 % 100 % 10;
	int cal_12 = 0;
	int cal_16 = 0;
	make_12(a, 0);
	make_16(a, 0);

	for (int i = 0; i <= cnt_12; i++){
		cal_12 += tmp_12[i];
	}
	for (int i = 0; i <= cnt_16; i++){
		cal_16 += tmp_16[i];
	}
	if (cal_10 == cal_12 && cal_10 == cal_16) {
		cout << a << endl;
	}
}

int main() {
	for (int i = 1000; i < 10000; i++) {
		cal(i);
	}

	return 0;
}