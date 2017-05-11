#include <iostream>
using namespace std;

int n;
int house[1001][3];
int compare[3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	for (int i = 0; i < n-1; i++) {
		// compare 초기화
		for (int j = 0; j < 3; j++) {
			compare[j] = 0;
		}
		// 연산
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j!=k && compare[k] == 0) {
					compare[k] = house[i][j] + house[i + 1][k];
				}
				else if (j != k && house[i][j]+house[i+1][k] < compare[k]) {
					compare[k] = house[i][j] + house[i+1][k];
				}
			}
		}
		//대입
		for (int j = 0; j < 3; j++) {
			house[i + 1][j] = compare[j];
		}

	}
	int min = 9999999;
	for (int a = 0; a < 3; a++) {
		if (min > house[n - 1][a]) {
			min = house[n - 1][a];
		}
	}
	cout << min;
	return 0;
}