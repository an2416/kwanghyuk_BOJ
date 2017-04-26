#include <iostream>
using namespace std;

int a[1001][3],n, counting[3][4], sum[3],Max=0;

void arr_init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			counting[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		sum[i] = 0;
	}
}

int main() {
	int n, compare[3],compare_add=0;
	cin >> n;
	
	arr_init();

	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		
		sum[0] += a[i][0];
		sum[1] += a[i][1];
		sum[2] += a[i][2];

		counting[0][a[i][0]]++;
		counting[1][a[i][1]]++;
		counting[2][a[i][2]]++;
	}

	for (int i = 0; i < 3; i++) {
		if (Max < sum[i]) {
			Max = sum[i];
		}
	}

	for (int i = 0; i < 3; i++) {
		if (Max == sum[i]) {
			compare[compare_add++] = i;
		}
	}

	if (compare_add == 1) {
		cout << compare[0]+1 << " " << sum[compare[0]] << endl;
	}
	else if (compare_add == 2) {
		if (counting[compare[0]][3] == counting[compare[1]][3]) {
			if (counting[compare[0]][2] == counting[compare[1]][2]) {
				cout << 0 << " " << sum[compare[0]] << endl;
			}
			else if (counting[compare[0]][2] < counting[compare[1]][2]) {
				cout << compare[1]+1 << " " << sum[compare[1]] << endl;
			}
			else {
				cout << compare[0]+1 << " " << sum[compare[0]] << endl;
			}
		}
		else if (counting[compare[0]][3] < counting[compare[1]][3]) {
			cout << compare[1]+1 << " " << sum[compare[1]] << endl;
		}
		else {
			cout << compare[0]+1 << " " << sum[compare[0]] << endl;
		}
	}
	else if (compare_add == 3) {
		if (counting[0][3] > counting[1][3] && counting[0][3] > counting[2][3]) {
			cout << 1 << " " << sum[0] << endl;
		}
		else if (counting[1][3] > counting[0][3] && counting[1][3] > counting[2][3]) {
			cout << 2 << " " << sum[1] << endl;
		}
		else if (counting[2][3] > counting[0][3] && counting[2][3] > counting[1][3]) {
			cout << 3 << " " << sum[2] << endl;
		}
		else if(counting[0][3] == counting[1][3]){
			if (counting[0][2] == counting[1][2]) {
				cout << 0 << " " << sum[0] << endl;
			}
			else if (counting[0][2] < counting[1][2]) {
				cout << 2 << " " << sum[1] << endl;
			}
			else {
				cout << 1 << " " << sum[0] << endl;
			}
		}
		else if (counting[2][3] == counting[1][3]){
			if (counting[2][2] == counting[1][2]) {
				cout << 0 << " " << sum[0] << endl;
			}
			else if (counting[2][2] < counting[1][2]) {
				cout << 2 << " " << sum[1] << endl;
			}
			else {
				cout << 3 << " " << sum[2] << endl;
			}
		}
		else if (counting[0][3] == counting[2][3]){
			if (counting[0][2] == counting[2][2]) {
				cout << 0 << " " << sum[0] << endl;
			}
			else if (counting[0][2] < counting[2][2]) {
				cout << 3 << " " << sum[2] << endl;
			}
			else {
				cout << 1 << " " << sum[0] << endl;
			}
		}
	}

	return 0;
}