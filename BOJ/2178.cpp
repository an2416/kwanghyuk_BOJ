#include <iostream>
using namespace std;

int n, m;
char input_map[101][101];
int map[101][101];
int que_x[10001];
int que_y[10001];
int head_x=0, tail_x=0, head_y=0, tail_y=0;
int dest_x, dest_y;
int cnt = 2;

void push(int x, int y) {
	que_x[tail_x++] = x;
	que_y[tail_y++] = y;
}

int pop_x() {
	return que_x[head_x++];
}

int pop_y() {
	return que_y[head_y++];
}

void bfs() {
	while (head_x != tail_x) {
		int x = pop_x();
		int y = pop_y();

		if (x == dest_x && y == dest_y) {
			break;
		}

		if (x + 1 < n && map[x + 1][y] == 1) {
			push(x + 1, y);
			map[x + 1][y] = map[x][y] + 1;
		}
		if (x - 1 >= 0 && map[x - 1][y] == 1) {
			push(x - 1, y);
			map[x - 1][y] = map[x][y] + 1;
		}
		if (y + 1 < m && map[x][y+1] == 1) {
			push(x, y+1);
			map[x][y+1] = map[x][y] + 1;
		}
		if (y - 1 >= 0 && map[x][y - 1] == 1) {
			push(x, y - 1);
			map[x][y - 1] = map[x][y] + 1;
		}
	}
}

int main() {
	cin >> n >> m;
	dest_x = n - 1;
	dest_y = m - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input_map[i][j];
			map[i][j] = input_map[i][j] - '0';
		}
	}

	push(0, 0);
	map[0][0] = cnt;
	bfs();
	cout << map[dest_x][dest_y] - 1;
	return 0;
}