#include <iostream>
using namespace std;

int que_x[100001];
int que_y[100001];
int head_x, tail_x, head_y, tail_y;
int n, m;
long long box[1001][1001];

void push(int x, int y) {
	que_x[tail_x++] = x;
	que_y[tail_y++] = y;
	tail_x %= 100001;
	tail_y %= 100001;
}

int pop_x() {
	int xx = que_x[head_x];
	head_x++;
	head_x %= 100001;
	return xx;
}

int pop_y() {
	int yy = que_y[head_y];
	head_y++;
	head_y %= 100001;
	return yy;

}

void bfs() {
	while (head_x!=tail_x) {
		int x = pop_x();
		int y = pop_y();

		if (x + 1 <= n-1 && box[x + 1][y] == 0) {
			push(x + 1, y);
			box[x + 1][y] = box[x][y] + 1;
		}
		if (x - 1 >= 0 && box[x - 1][y] == 0) {
			push(x - 1, y);
			box[x - 1][y] = box[x][y] + 1;
		}
		if (y + 1 <= m-1 && box[x][y+1] == 0) {
			push(x, y+1);
			box[x][y+1] = box[x][y] + 1;
		}
		if (y - 1 >= 0 && box[x][y - 1] == 0) {
			push(x, y - 1);
			box[x][y - 1] = box[x][y] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int flag = 0,compare_flag=0;
	head_x = 0; 
	tail_x = 0; 
	head_y = 0; 
	tail_y = 0;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				flag++;
				push(i, j);
			}
		}
	}

	bfs();
	int Max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] != 0 && box[i][j] != -1) {
				compare_flag++;
			}
			if (box[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			else if(box[i][j] > Max){
				Max = box[i][j];
			}
		}
	}

	if (compare_flag == flag) {
		cout << 0 << '\n';
		return 0;
	}
	cout << Max-1 << '\n';
	return 0;
}