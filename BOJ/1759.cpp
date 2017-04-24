#include <iostream>
using namespace std;

char word[16];
char print[16];

int combi(int a, int b) {
	
	if (a == b || b == 0) {
		cout << word[a] << " ";
		return 1;
	}
	else {
		return combi(a - 1, b - 1) + combi(a-1, b);
	}
}

int main() {
	int a, b;
	
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		cin >> word[i];
	}

	cout << combi(b, a) << endl;
	return 0;
}