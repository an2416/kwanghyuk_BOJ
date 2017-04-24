#include <iostream>
using namespace std;

int main() {
	int a, b, c, sum,result[10], check[10];
	
	cin >> a >> b >> c;
	sum = a*b*c;

	for (int i = 9; i >= 0; i--) {	
		int tmp = 1;
		for (int j = 0; j < i; j++) {
			tmp = tmp * 10;
		}
		result[9-i] = sum / tmp;
		sum = sum% tmp;
	}	

	for (int i = 0; i <= 9; i++) {
		check[i] = 0;
	}

	int flag = 0;
	for (int i = 0; i < 10; i++) {
		if (result[i] != 0) {
			flag = 1;
		}
		if (flag == 1) {
			check[result[i]]++;
		}
	}

	for (int i = 0; i <= 9; i++) {
		cout << check[i] << endl;
	}
	return 0;
}