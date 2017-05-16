#include <iostream>
using namespace std;

int n,stair[301];
int dp[301];

int Max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	dp[0] = stair[0]; // 첫번째 계단
	dp[1] = Max(stair[0]+stair[1],stair[1]); // 두번째 갈때는 두칸 or 한칸+한칸 갔을경우
	dp[2] = Max(stair[0]+stair[2],stair[1]+stair[2]); // 세번째 갈때는 한칸+두칸 or 두칸+한칸

	for (int i = 3; i < n; i++) {
		dp[i] = Max(dp[i-2]+stair[i], stair[i-1]+stair[i]+dp[i-3]); // 네번째부터는 현재칸+전전칸 or 전전전칸+전칸+현재칸
	}

	cout << dp[n - 1] << '\n';

	return 0;
}