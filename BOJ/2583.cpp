#include <iostream>
using namespace std;

int map[101][101];
int m,n,k;
int que_x[10001];
int que_y[10001];
int head_x = 0, tail_x = 0;
int head_y = 0, tail_y = 0;
int cnt = 2;
int Max[10000];
int Max_add = 0;
int Max_cnt = 1;

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

		if (x + 1 < m && map[x + 1][y] == 0) {
			push(x + 1, y);
			Max[Max_add] = Max_cnt++;
			map[x+1][y] = cnt;
		}
		if (x - 1 >= 0 && map[x - 1][y] == 0) {
			push(x - 1, y);
			Max[Max_add] = Max_cnt++;
			map[x-1][y] = cnt;
		}
		if (y + 1 < n && map[x][y+1] == 0) {
			push(x, y+1);
			Max[Max_add] = Max_cnt++;
			map[x][y+1] = cnt;
		}
		if (y - 1 >= 0 && map[x][y-1] == 0) {
			push(x, y-1);
			Max[Max_add] = Max_cnt++;
			map[x][y-1] = cnt;
		}
	}
}

void debugging() {
	cout << '\n' << '\n';
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int yy = y1; yy < y2;yy++) {
			for (int xx = x1; xx < x2; xx++) {
				map[yy][xx] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && map[i][j] != 1) {
				Max_cnt = 1;
				head_x = 0;
				head_y = 0;
				tail_x = 0;
				tail_y = 0;
				push(i, j);
				map[i][j] = cnt;
				Max[Max_add] = Max_cnt++;
				bfs();
				cnt++;
				Max_add++;
			}
		}
	}

	for (int i = 0; i < Max_add-1; i++) {
		for (int j = i+1; j < Max_add; j++) {
			if (Max[i] > Max[j]) {
				int tmp = Max[j];
				Max[j] = Max[i];
				Max[i] = tmp;
			}
		}
	}

	cout << cnt - 2 << '\n';
	for (int i = 0; i < Max_add; i++) {
		cout << Max[i] << " ";
	}
	return 0;
}