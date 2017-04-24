#include <iostream>
#include <time.h>
using namespace std;

// 메모이제이션
// 재귀함수에서 필요한 값을 계속 저장시켜 놓고 필요할 때마다 꺼내서 쓰는 방법
// 계산을 계속 하는것보다 꺼내서 쓰기때문에 빠르다

//예제 : 피보나치수열
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
	cout << "------ 일반 재귀 ------" << endl;
	cout << result << endl;
	cout << a << "개    " << gap << "초 소요" << endl << endl;

	startTime = clock();
	result = memo_fibo(a);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ 메모이제이션 ------" << endl;
	cout << result << endl;
	cout << a << "개    " << gap << "초 소요" << endl << endl;

	startTime = clock();
	result = for_func(a);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ FOR 문 ------" << endl;
	cout << result << endl;
	cout << a << "개    " << gap << "초 소요" << endl << endl;

	return 0;
}