#include <iostream>
using namespace std;

int N, M;
int map[501][501], visit[501][501];
int sum, Max = 0,cnt=0;

void visit_init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	cnt++;
	sum += map[x][y];
	if (cnt == 4) {
		if (Max < sum) {
			Max = sum;
		}
		return;
	}

	if (x - 1 >= 0 && visit[x-1][y]==0 && cnt<4) {
		dfs(x - 1, y);
		visit[x - 1][y] = 0;
		cnt--;
		sum -= map[x - 1][y];
	}
	if (x + 1 <= N && visit[x + 1][y] == 0 && cnt<4) {
		dfs(x + 1, y);
		visit[x + 1][y] = 0;
		cnt--;
		sum -= map[x + 1][y];
	}
	if (y - 1 >= 0 && visit[x][y - 1] == 0 && cnt<4) {
		dfs(x, y-1);
		visit[x][y-1] = 0;
		cnt--;
		sum -= map[x][y-1];
	}
	if (y + 1 <= M && visit[x][y + 1] == 0 && cnt<4) {
		dfs(x, y+1);
		visit[x][y+1] = 0;
		cnt--;
		sum -= map[x][y + 1];
	}
}

int case_a(int x, int y) {
	if (y - 1 >= 0 && y + 1 <= M && x + 1 <= N) {
		return map[x][y-1] + map[x][y] + map[x][y+1] + map[x + 1][y];
	}
	return 0;
}

int case_b(int x, int y) {
	if (x-1 >= 0 && y-1>=0 && y+1<=M) {
		return map[x][y] + map[x-1][y] + map[x+1][y-1] + map[x+1][y+1];
	}
	return 0;
}

int case_c(int x, int y) {
	if (x-1>=0 && x+1 <=N && y+1 <=M) {
		return map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y+1];
	}
	return 0;
}

int case_d(int x, int y) {
	if (x-1>=0&&x+1<=N && y-1>=0) {
		return map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y-1];
	}
	return 0;
}

int case_loop(int num,int x, int y) {
	if (num == 0) {
		return case_a(x, y);
	}
	else if (num == 1) {
		return case_b(x, y);
	}
	else if (num == 2) {
		return case_c(x, y);
	}
	else if (num == 3) {
		return case_d(x, y);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	//¿¬»êºÎ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt = 0;
			sum = 0;
			visit_init();
			dfs(i, j);
			for (int aa = 0; aa < 4; aa++) {
				int result = case_loop(aa, i, j);
				if (result > Max) {
					Max = result;
				}
			}
		}
	}

	cout << Max << '\n';
	return 0;
}