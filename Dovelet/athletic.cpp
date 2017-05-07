#include <iostream>
using namespace std;

// n번 연속 이겼을경우
// n-1번 이기고 1번 졌을 경우

int a,cnt=0,result_add=0;
char result[1000];

void match(int k,int o, int x) {
	if (x >= a) {
		return;
	}
	if (o >= a) {
		cnt++;
		for (int i = 0; i < k; i++) {
			cout << result[i];
		}
		cout << '\n';
		return;
	}
	result[k] = 'o';
	match(k+1,o + 1, x);
	result[k] = 'x';
	match(k+1,o, x + 1);
}

int main() {
	cin >> a;
	match(0,0, 0);
	cout << "total " << cnt << " case(s)";
	return 0;
}