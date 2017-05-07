#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int st[10001];
	int sp = 0;
	int tmp;
	string a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			cin >> tmp;
			st[sp++] = tmp;
		}
		else if (a == "pop") {
			if (sp - 1 < 0) {
				cout << -1 << '\n';
			}
			else {
				cout << st[--sp] << '\n';
			}
		}
		else if (a == "size") {
			cout << sp << '\n';
		}
		else if (a == "empty") {
			if (sp == 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (a == "top") {
			if (sp - 1 < 0) {
				cout << -1 << '\n';
			}
			else {
				cout << st[sp - 1] << '\n';
			}
		}
	}
	return 0;
}