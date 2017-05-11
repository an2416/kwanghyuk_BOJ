#include <iostream>
using namespace std;

int n;
int tri[501][501];

void dp(int ii, int jj) {
	if (tri[ii-1][jj-1] > tri[ii-1][jj]) {
		tri[ii][jj] += tri[ii - 1][jj - 1];
	}
	else {
		tri[ii][jj] += tri[ii - 1][jj];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 && i>0) {
				tri[i][j] = tri[i][j] + tri[i-1][j];
			}
			else if (j == i && i>0 && j>0) {
				tri[i][j] = tri[i][j] + tri[i - 1][j - 1];
			}
			else {
				dp(i, j);
			}
		}
	}

	int Max = 0;
	for (int i = 0; i < n; i++) {
		if (tri[n - 1][i] > Max) {
			Max = tri[n - 1][i];
		}
	}
	cout << Max << '\n';
	return 0;
}