#include <iostream>
using namespace std;

// n�� ����
// n���� k���� 1��
// �ߺ�X

int tmp[50],n,k;

void init(int a) {
	for (int i = 0; i < a; i++) {
		tmp[i] = 0;
	}
}

void pat(int start, int end, int num) { // for�� ����, ����, n�� ������ n �Է�
	if (num <= 0) {
		return;
	}
	else {
		for (int i = start; i < end; i++) {
			tmp[i] = 1;
			pat(i+1, end+1, num - 1);
			if (end == n) {   // ��ͷ� for���� ����鼭 n�� ������ n��° ���������� �����ϵ��� ����
				for (int j = 0; j < n; j++) {
					cout << tmp[j];
				}
				cout << endl;
			}
			tmp[i] = 0;  // �ϳ��� �����Ͽ� ��������� �ٽ� ���󺹱�
		}
	}
}

int main() {
	cin >> n >> k;
	init(n);
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			cout << "0";
		}
		return 0;
	}
	pat(0,n-k+1,k);
	return 0;
}