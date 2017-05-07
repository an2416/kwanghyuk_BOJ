#include <iostream>
using namespace std;

int main()
{
	int n, number, rear = 1, stack[100001], top = 0, cnt = 0;
	char No[200002];
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> number;
		if (number > n || stack[top] > number) { cout << "NO" << '\n'; return 0; }
		while (rear <= number) {
			stack[++top] = rear++;
			No[cnt++] = '+';
		}
		top--;
		No[cnt++] = '-';
	}
		
	for (int i = 0; i < cnt; i++) {
		cout << No[i] << '\n';
	}

	return 0;
}