#include <iostream>
using namespace std;

int n, counting[8002],input[500001],Max=-4001,Min=4001,sum=0;
int input_copy[500001];

void merge(int data[], int start, int mid, int end) {
	int left_index = start;
	int right_index = mid+1;
	int add = 0;

	while (left_index <= mid && right_index <= end) {
		if (input[left_index] < input[right_index]) {
			input_copy[add] = input[left_index++];
		}
		else {
			input_copy[add] = input[right_index++];
		}
		add++;
	}

	while (left_index <= mid) {
		input_copy[add++] = input[left_index++];
	}
	while (right_index <= end) {
		input_copy[add++] = input[right_index++];
	}
	add = 0;
	for (int i = start; i <= end;i++) {
		input[i] = input_copy[add++];
	}
}

void merge_sort(int data[],int start,int end) {
	if (end-start<1) {
		return;
	}
	int mid = (start+end) / 2;
	merge_sort(data, start, mid);
	merge_sort(data, mid + 1, end);
	merge(data, start, mid, end);
}

int counting_max() {
	int count_max = 0;
	int flag = 0;
	int min[500001];
	int min_add = 0;
	min[0] = 10000;

	for (int i = 0; i < 8002; i++) {
		if (count_max < counting[i]) {
			count_max = counting[i];
		}
	}
	for (int i = 0; i < 8002; i++) {
		if (count_max == counting[i]) {
			min[min_add++] = i;
		}
	}
	if (min_add >= 2) {
		for (int i = 0; i < min_add-1; i++) {
			for (int j = i + 1; j < min_add; j++) {
				int a = min[i], b=min[j];
				if (min[i] <= 4000) {
					a *= -1;
				}
				else if (min[i] > 4000) {
					a -= 4000;
				}
				if (min[j] <= 4000) {
					b *= -1;
				}
				else if (min[j] > 4000) {
					b -= 4000;
				}
				//cout << a << "     " << b << endl;
				if (a > b) {
					int tmp = min[j];
					min[j] = min[i];
					min[i] = tmp;
				}
			}
		}
		if (min[1] <= 4000) {
			min[1] *= -1;
		}
		else if (min[1] > 4000) {
			min[1] -= 4000;
		}
		return min[1];
	}
	if (min[0] <= 4000) {
		min[0] *= -1;
	}
	else if (min[0] > 4000) {
		min[0] -= 4000;
	}
	return min[0];
}

int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 8002; i++) {
		counting[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		if (Min > input[i]) {
			Min = input[i];
		}
		if (Max < input[i]) {
			Max = input[i];
		}
		sum += input[i];
		if (input[i] <= 0) {
			counting[-1 * input[i]]++;
		}
		else if (input[i] > 0) {
			counting[input[i] + 4000]++;
		}
	}

	//Æò±Õ
	if (sum < 0) {
		cout << (int)((float)sum / (float)n - 0.5) << '\n';
	}
	else {
		cout << (int)(((float)sum / (float)n) + 0.5) << '\n';
	}
	//Áß¾Ó°ª
	merge_sort(input, 0, n - 1);
	if (n % 2 == 0) {
		cout << input[(n / 2) - 1] << '\n';
	}
	else {
		cout << input[n / 2] << '\n';
	}
	//ÃÖºó°ª
	cout << counting_max() << '\n';
	//¹üÀ§
	cout << Max - Min << '\n';
	return 0;
}