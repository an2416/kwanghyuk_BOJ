#include <iostream>
using namespace std;

int n;
int space[1000001];    // 입력 받을 공간
int space_copy[1000001];  // 병합과정에서 임시로 저장할 공간

void merge(int data[],int start, int mid, int end) {
	int left_index = start;  // 반으로 쪼갠것 중 왼쪽 index
	int right_index = mid + 1;  // 반으로 쪼갠것 중 오른쪽 index
	int copy_add = 0;  // 병합과정에서 임시로 저장해둘 공간의 index 초기화

	while (left_index <= mid && right_index <= end) {   // 왼쪽은 left_index~mid , 오른쪽은 min+1 ~ right_index 까지
		if (data[left_index] < data[right_index]) {  // 두개의 공간중 왼쪽 숫자가 더 작으면
			space_copy[copy_add] = data[left_index++];  // 임시 공간에 왼쪽 숫자를 저장
		}
		else {
			space_copy[copy_add] = data[right_index++];  // 임시 공간에 오른쪽 숫자를 저장
		}
		copy_add++;  // 임시공간에 저장후 임시공간 index++
	}

	//끼워넣기 (위의 과정을 거치면서 left_index또는 right_index가 조건을 넘어 나온경우 남아있는 수를 임시공간에 끼워 넣어야함.)
	while (left_index <= mid) {
		space_copy[copy_add++] = data[left_index++];
	}
	while (right_index <= end) {
		space_copy[copy_add++] = data[right_index++];
	}

	copy_add = 0;    // 임시공간 index 초기화
	for (int i = start; i <= end; i++) {  // 원래 데이터 배열 start~end까지 정렬이 완료되었으므로 다시 삽입해 준다.
		space[i] = space_copy[copy_add++];
	}
}

void merge_sort(int data[], int start, int end) {
	if (end - start < 1) {   // end == start 이면 쪼갤수 있는 만큼 다쪼갰다는 뜻
		return;
	}
	int mid = (start + end) / 2;  // 반으로 쪼개기
	merge_sort(data,start, mid);    // 왼쪽 분할
	merge_sort(data,mid + 1, end);  // 오른쪽 분할 (mid+1을 해주어야 index가 겹치지 않음.)
	merge(data, start, mid, end);  // 병합
}

int main() {
	// 입력 방법에 따른 시간 차이
	// scanf : 0.798 sec
	// getchar(*) : 0.390 sec
	// cin : 2.051 sec
	// std::ios::sync_with_stdio(false) + std::cin : 0.796 sec
	ios::sync_with_stdio(false);  // 동기화를 false 시킴으로써 cin의 속도를 향상시킴.
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> space[i];
	}

	merge_sort(space, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << space[i] << '\n';  // endl을 쓸때보다 '\n'으로 쓰는게 훨씬 빠름. cout보다 printf가 더빠름.
	}
	return 0;
}