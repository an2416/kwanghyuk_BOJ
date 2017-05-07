#include <iostream>
using namespace std;

int map[101][101];
int copy_map[101][101];
int head = 0, tail = 0;
int que[10001];
int n;

void push(int x) {
	que[tail++] = x;
}

int pop() {
	return que[head++];
}

bool bfs(int end) {
	while (1) {
		if (head == tail) {
			return false;
		}

		int start_tmp = pop();
		if (start_tmp == end) {
			return true;
		}

		for (int i = 0; i < n; i++) {
			if (copy_map[start_tmp][i] == 1) {
				copy_map[start_tmp][i] = 2;
				push(i);
			}
		}
	}
}

void copy_m() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}

void debugging() {
	cout << "-- bfs --" << '\n';
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			cout << copy_map[a][b];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	//탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			head = 0; tail = 0; // 큐 초기화
			copy_m(); // 방문 초기화
			for (int a = 0; a < n; a++) {
				if (copy_map[i][a] == 1 && a!=i) {
					copy_map[i][a] = 2;
					push(a);
				}
			}
			bool tmp_b = bfs(j);
			if (tmp_b) {
				cout << "1";
			}
			else {
				cout << "0";
			}
			cout << " ";
		}
		cout << '\n';
	}

	return 0;
}