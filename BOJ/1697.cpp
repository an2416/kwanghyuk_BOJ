#include <iostream>
using namespace std;

int n, k;
int que[100001];
int num_chk[100001] = {0,};
int head = 0, tail = 0;

void push(int num) {
	que[tail++] = num;
}

int pop() {
	return que[head++];
}

void search() {
	while (head!=tail) {
		int tmp = pop();

		if (tmp == k) {
			cout << num_chk[tmp]-1 << '\n';
			break;
		}

		if (tmp * 2 <= 100000 && num_chk[tmp*2]==0) {
			push(tmp * 2);
			num_chk[tmp * 2] = num_chk[tmp] + 1;
		}
		if (tmp - 1 >= 0 && num_chk[tmp -1] == 0) {
			push(tmp - 1);
			num_chk[tmp - 1] = num_chk[tmp]+1;
		}
		if (tmp + 1 <= 100000 && num_chk[tmp +1] == 0) {
			push(tmp + 1);
			num_chk[tmp + 1] = num_chk[tmp] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	push(n);
	num_chk[n] = 1;
	search();

	return 0;
}