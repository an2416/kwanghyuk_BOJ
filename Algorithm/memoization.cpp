#include <iostream>
#include <time.h>
using namespace std;

// �޸������̼�
// ����Լ����� �ʿ��� ���� ��� ������� ���� �ʿ��� ������ ������ ���� ���
// ����� ��� �ϴ°ͺ��� ������ ���⶧���� ������

//���� : �Ǻ���ġ����
time_t startTime = 0, endTime = 0;
int memo[10001];
int for_arr[10001];

int fibo(int a) {
	if (a == 1) {
		return 1;
	}
	else if (a == 2) {
		return 2;
	}
	else {
		return fibo(a - 1) + fibo(a - 2);
	}
}

int memo_fibo(int a) {
	if (a == 1) {
		return 1;
	}
	else if (a == 2) {
		return 2;
	}
	else if (memo[a] != NULL) {
		return memo[a];
	}
	else {
		memo[a] = memo_fibo(a - 1) + memo_fibo(a - 2);
		return memo[a];
	}
}

int for_func(int a) {
	for_arr[0] = 1;
	for_arr[1] = 2;
	for (int i = 2; i < a; i++) {
		for_arr[i] = for_arr[i - 1] + for_arr[i - 2];
	}
	return for_arr[a-1];
}

int main() {
	int a, result;
	cin >> a;

	startTime = clock();
	result = fibo(a);
	endTime = clock();
	float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ �Ϲ� ��� ------" << endl;
	cout << result << endl;
	cout << a << "��    " << gap << "�� �ҿ�" << endl << endl;

	startTime = clock();
	result = memo_fibo(a);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ �޸������̼� ------" << endl;
	cout << result << endl;
	cout << a << "��    " << gap << "�� �ҿ�" << endl << endl;

	startTime = clock();
	result = for_func(a);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ FOR �� ------" << endl;
	cout << result << endl;
	cout << a << "��    " << gap << "�� �ҿ�" << endl << endl;

	return 0;
}