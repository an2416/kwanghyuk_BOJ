#include <iostream>
using namespace std;

int sum(int a) {
	int result_sum = 0;
	for (int i = 1; i <= a; i++) {
		result_sum += i;
	}
	return result_sum;
}

int main() {
	int x;
	cin >> x;
	// 1~N �ձ��ϱ�
	int add = 1;
	while (1) {
		if (sum(add-1) < x && sum(add) >= x) {
			break;
		}
		add++;
	}
	int tmp = sum(add-1);
	int count;
	for (int i = 1; i <= add; i++) {
		if (x == tmp + i) {
			count = i;
			break;
		}
	}
	
	//¦���϶� ���� �Ʒ���
	if (add % 2 == 0) {
		int i = 1, j = add;
		for (int cc = 1; cc < count; cc++) {
			i += 1;
			j -= 1;
		}
		cout << i << "/" << j << endl;
	}
	//Ȧ���϶� ������ ����
	else if (add % 2 == 1) {
		int i = add, j = 1;
		for (int cc = 1; cc < count; cc++) {
			j += 1;
			i -= 1;
		}
		cout << i << "/" << j << endl;
	}


	return 0;
}
