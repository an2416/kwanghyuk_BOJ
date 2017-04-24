#include <iostream>
using namespace std;

int n;
int space[1000001];    // �Է� ���� ����
int space_copy[1000001];  // ���հ������� �ӽ÷� ������ ����

void merge(int data[],int start, int mid, int end) {
	int left_index = start;  // ������ �ɰ��� �� ���� index
	int right_index = mid + 1;  // ������ �ɰ��� �� ������ index
	int copy_add = 0;  // ���հ������� �ӽ÷� �����ص� ������ index �ʱ�ȭ

	while (left_index <= mid && right_index <= end) {   // ������ left_index~mid , �������� min+1 ~ right_index ����
		if (data[left_index] < data[right_index]) {  // �ΰ��� ������ ���� ���ڰ� �� ������
			space_copy[copy_add] = data[left_index++];  // �ӽ� ������ ���� ���ڸ� ����
		}
		else {
			space_copy[copy_add] = data[right_index++];  // �ӽ� ������ ������ ���ڸ� ����
		}
		copy_add++;  // �ӽð����� ������ �ӽð��� index++
	}

	//�����ֱ� (���� ������ ��ġ�鼭 left_index�Ǵ� right_index�� ������ �Ѿ� ���°�� �����ִ� ���� �ӽð����� ���� �־����.)
	while (left_index <= mid) {
		space_copy[copy_add++] = data[left_index++];
	}
	while (right_index <= end) {
		space_copy[copy_add++] = data[right_index++];
	}

	copy_add = 0;    // �ӽð��� index �ʱ�ȭ
	for (int i = start; i <= end; i++) {  // ���� ������ �迭 start~end���� ������ �Ϸ�Ǿ����Ƿ� �ٽ� ������ �ش�.
		space[i] = space_copy[copy_add++];
	}
}

void merge_sort(int data[], int start, int end) {
	if (end - start < 1) {   // end == start �̸� �ɰ��� �ִ� ��ŭ ���ɰ��ٴ� ��
		return;
	}
	int mid = (start + end) / 2;  // ������ �ɰ���
	merge_sort(data,start, mid);    // ���� ����
	merge_sort(data,mid + 1, end);  // ������ ���� (mid+1�� ���־�� index�� ��ġ�� ����.)
	merge(data, start, mid, end);  // ����
}

int main() {
	// �Է� ����� ���� �ð� ����
	// scanf : 0.798 sec
	// getchar(*) : 0.390 sec
	// cin : 2.051 sec
	// std::ios::sync_with_stdio(false) + std::cin : 0.796 sec
	ios::sync_with_stdio(false);  // ����ȭ�� false ��Ŵ���ν� cin�� �ӵ��� ����Ŵ.
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> space[i];
	}

	merge_sort(space, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << space[i] << '\n';  // endl�� �������� '\n'���� ���°� �ξ� ����. cout���� printf�� ������.
	}
	return 0;
}