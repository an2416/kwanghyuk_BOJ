#include <iostream>
using namespace std;

int map[51][51];
int ga,se,num;
int que_x[10001];
int que_y[10001];
int head_x, tail_x, head_y, tail_y;
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
	while (head_x != tail_x) {
		int x = pop_x();
		int y = pop_y();

		if (x + 1 <= se && map[x+1][y] == 1) {
			push(x + 1, y);
			map[x+1][y] = cnt;
		}
		if (x - 1 >= 0 && map[x-1][y] == 1) {
			push(x - 1, y);
			map[x-1][y] = cnt;
		}
		if (y + 1 <= ga && map[x][y+1] == 1) {
			push(x, y+1);
			map[x][y+1] = cnt;
		}
		if (y - 1 >= 0 && map[x][y-1] == 1) {
			push(x, y-1);
			map[x][y-1] = cnt;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++) {
		cin >> ga >> se >> num;
		// map 초기화
		for (int i = 0; i < se; i++) {
			for (int j = 0; j < se; j++) {
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < num; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		//cnt 초기화
		cnt = 2;

		//연산
		for (int i = 0; i < se; i++) {
			for (int j = 0; j < ga; j++) {
				if (map[i][j] == 1) {
					//큐 초기화
					head_x = 0; tail_x = 0;
					head_y = 0; tail_y = 0;
					push(i, j);
					map[i][j] = cnt;
					bfs();
					cnt++;
				}
			}
		}

		//출력
		cout << cnt - 2 << '\n';
	}

	return 0;
}