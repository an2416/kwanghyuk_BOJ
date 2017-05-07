#include <iostream>
using namespace std;

int n;
int map[301][301];
int copy_m[301][301];
int que_x[10001];
int que_y[10001];
int head_x, tail_x, head_y, tail_y;
int start_x, start_y, dest_x, dest_y;
int cnt;

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
	while (head_x!=tail_x) {
		int x = pop_x();
		int y = pop_y();
		
		if (x == dest_x && y == dest_y) {
			break;
		}

		if (x - 2 >= 0 && y - 1 >= 0 && map[x - 2][y - 1] == 0) {
			push(x - 2, y - 1);
			map[x - 2][y - 1] = map[x][y]+1;
		}
		if (x - 1 >= 0 && y - 2 >= 0 && map[x - 1][y - 2] == 0) {
			push(x - 1, y - 2);
			map[x - 1][y - 2] = map[x][y] + 1;
		}
		if (x - 2 >= 0 && y + 1 <= n && map[x - 2][y + 1] == 0) {
			push(x - 2, y + 1);
			map[x - 2][y + 1] = map[x][y] + 1;
		}
		if (x - 1 >= 0 && y + 2 <= n && map[x - 1][y + 2] == 0) {
			push(x - 1, y + 2);
			map[x - 1][y + 2] = map[x][y] + 1;
		}
		if (x + 1 <= n && y - 2 >= 0 && map[x + 1][y - 2] == 0) {
			push(x + 1, y - 2);
			map[x + 1][y - 2] = map[x][y] + 1;
		}
		if (x + 2 <= n && y - 1 >= 0 && map[x + 2][y - 1] == 0) {
			push(x + 2, y - 1);
			map[x + 2][y - 1] = map[x][y] + 1;
		}
		if (x + 1 <= n && y + 2 <= n && map[x + 1][y + 2] == 0) {
			push(x + 1, y + 2);
			map[x + 1][y + 2] = map[x][y] + 1;
		}
		if (x + 2 <= n && y + 1 <= n && map[x + 2][y + 1] == 0) {
			push(x + 2, y + 1);
			map[x + 2][y + 1] = map[x][y] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		cin >> start_x >> start_y >> dest_x >> dest_y;
		//카운트 초기화
		cnt = 1;
		//큐 초기화
		head_x = 0; tail_x = 0;
		head_y = 0; tail_y = 0;
		// map 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = 0;
			}
		}
		map[start_x][start_y] = cnt;
		push(start_x, start_y);
		bfs();
		cout << map[dest_x][dest_y] - 1 << '\n';
	}

	return 0;
}