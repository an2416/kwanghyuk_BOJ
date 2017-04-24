#include <iostream>
#include <time.h>
using namespace std;

time_t startTime = 0, endTime = 0;

// 재귀는 메모이제이션 활용해야 빠름
int memo[1001][1001];

int combi(int a, int b) {
	if (a == b || b==0) {
		return 1;
	}
	else {
		return combi(a - 1, b - 1) + combi(a - 1, b);
	}
}

int combi_memo(int a, int b) {
	if (a == b || b == 0) {
		return 1;
	}
	else if (memo[a][b]!=NULL) {
		return memo[a][b];
	}
	else {
		memo[a][b] = combi(a - 1, b - 1) + combi(a - 1, b);
		return memo[a][b];
	}
}

int main() {
	int n, r;
	cin >> n >> r;

	startTime = clock();
	int result = combi(n, r);
	endTime = clock();
	float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ 재귀 함수 ------" << endl;
	cout << result << endl;
	cout << gap << "초 소요" << endl << endl;

	startTime = clock();
	result = combi_memo(n, r);
	endTime = clock();
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
	cout << "------ 메모이제이션 ------" << endl;
	cout << result << endl;
	cout << gap << "초 소요" << endl << endl;


	return 0;
}