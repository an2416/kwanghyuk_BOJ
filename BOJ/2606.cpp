#include <iostream>
using namespace std;

int com, con, cnt=0;
int network[101][101];
int que[10001];
int head = 0, tail = 0;
int visit[101];

void push(int a) {
	que[tail++] = a;
}

int pop() {
	return que[head++];
}

void bfs() {
	while (head != tail) {
		int a = pop();
		visit[a] = 1;
		for (int i = 1; i <= com; i++) {
			if (network[a][i] == 1) {
				push(i);
				network[a][i] = 2;
				network[i][a] = 2;
			}
		}
	}
}

int main() {
	cin >> com >> con;
	for (int i = 1; i <= com; i++) {
		for (int j = 1; j <= com; j++) {
			network[i][j] = 0;
		}
		visit[i] = 0;
	}
	for (int i = 0; i < con; i++) {
		int a, b;
		cin >> a >> b;
		network[a][b] = 1;
		network[b][a] = 1;
	}

	push(1);
	bfs();

	for (int i = 1; i <= com; i++) {
		if (visit[i]) {
			cnt++;
		}
	}

	cout << cnt-1 << '\n';
	return 0;
}