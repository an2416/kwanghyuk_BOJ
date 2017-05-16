#include <iostream>
using namespace std;

int main() {
	int n;
	long long dp[91];
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	if (n == 1 || n==2) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << '\n';
	return 0;
}


//#include <iostream>
//using namespace std;
//
//long long result[91];
//
//long long fibo(int a) {
//	if (a == 1 || a == 2) {
//		return 1;
//	}
//	if (result[a] != NULL) {
//		return result[a];
//	}
//	return result[a] = fibo(a - 1) + fibo(a - 2);
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << fibo(n) << '\n';
//
//	return 0;
//}