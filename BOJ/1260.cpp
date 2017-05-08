#include <iostream>
using namespace std;

int root[1001][1001];
int n, m, v;
int que[10001];
int head=0, tail=0;
int visit[1001];

void push(int start) {
	que[tail++] = start;
}

int pop() {
	return que[head++];
}

void bfs() {
	cout << v << " ";
	visit[v] = 1;
	while (head != tail) {
		int start = pop();
		for (int i = 0; i <= n; i++) {
			if (root[start][i] == 1 && visit[i]==0) {
				push(i);
				visit[i] = 1; // 방문 체크
				cout << i << " ";
			}
		}
	}
}

void visit_init() {
	for (int i = 0; i <= 1000; i++) {
		visit[i] = 0;
	}
}

void dfs(int start) {
	cout << start << " ";
	visit[start] = 1;
	for (int i = 0; i <= n; i++) {
		if (root[start][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> v;
	//root 초기화
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			root[i][j] = 0;
		}
	}
	// 간선 체크
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		root[start][end] = 1;
		root[end][start] = 1;
	}
	visit_init();
	dfs(v);
	cout << '\n';
	visit_init();
	push(v);
	bfs();
	
	return 0;
}