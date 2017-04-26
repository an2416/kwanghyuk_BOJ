//�̿ϼ� �ڵ�
//�ð��ʰ� ����

#include <iostream>
#include <cstdio>
#include <malloc.h>
using namespace std;

int n, k;
int *num, *all_num;  // ������ ���� ����

void quick_min(int s,int e) {
	int pivot = num[s];
	int left = s;
	int right = e;

	while (s < e) {
		while (pivot <= num[e] && (s < e)) {
			e--;
		}
		if (s > e) {
			break;
		}
		while (pivot >= num[s] && (s < e)) {
			s++;
		}
		if (s > e) {
			break;
		}
		swap(num[s], num[e]);
		if (left < s) {
			quick_min(left, s - 1);
		}
		if (right > e) {
			quick_min(s + 1, right);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // ����ȭ false
	cin >> n >> k;
	
	all_num = (int*)malloc(sizeof(int)*n); // n�� ũ�� ��ŭ ���� �Ҵ�
	num = (int*)malloc(sizeof(int)*k); // k�� ũ�� ��ŭ ���� �Ҵ�
	
	for (int i = 0; i < n; i++) {
		cin >> all_num[i];
	}

	long long sum = 0;
	for (int i = 0; i < n - k + 1; i++) {
		int num_add = 0;
		for (int j = i; j < i + k; j++) {
			num[num_add] = all_num[j];
			num_add++;
		}
		quick_min(0,k-1);
		if ((k + 1) % 2 == 0) {
			//cout << num[(k + 1) / 2 - 1] << endl;
			sum += num[((k + 1) / 2) - 1];
		}
		else {
			//cout << num[(k + 1) / 2] << endl;
			sum += num[((k + 1) / 2)];
		}
	}
	cout << sum << '\n';

	free(num); // �޸� ����
	free(all_num); // �޸� ����
	return 0;
}