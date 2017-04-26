#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	float price[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
	int tc, input[5];
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		float sum = 0.0;
		for (int i = 0; i < 5; i++) {
			cin >> input[i];
			sum += input[i] * price[i];
		}
		printf("$%.2f\n", sum);
	}
	return 0;
}