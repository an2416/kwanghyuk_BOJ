#include <iostream>
using namespace std;

int main() {
	int testcase;
	int apt[15][15];

	cin >> testcase;

	for (int i = 0; i <= 15; i++) {
		apt[0][i] = i;
	}

	for (int tc = 0; tc < testcase; tc++) {
		int floor, ho;
		cin >> floor >> ho;
		
		for (int aa = 1; aa <= floor; aa++) {
			apt[aa][0] = 0;
			for (int bb = 1; bb <= ho; bb++) {
				apt[aa][bb] = apt[aa][bb - 1] + apt[aa - 1][bb];
			}
		}
		cout << apt[floor][ho] << endl;
	}
	return  0;
}