/*
           ī���� ����            
 �ߺ��� ���� �����Ҷ� ����         
 ������ ������ �������϶� ����     
*/

#include <iostream>
using namespace std;

int main() {
	int n, num[10001];  // num���� ���ڴ� �ִ� ��� ���� ����
	for (int i = 0; i < 10001; i++) {  // 0���� �ʱ�ȭ �����־�� ���߿� ī������ �� ����.
		num[i] = 0;
	}
	ios::sync_with_stdio(false);  // ����ȭ false  -> cin �ӵ� �ش�ȭ
	cin >> n;

	for (int i = 0; i < n; i++) {    // �Է¹޴� ���� �迭�� index�� �Է¹޾� ī�������ش�.
		int a;
		cin >> a;
		num[a]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << '\n';   // endl -> '\n'���� ��� ����.
		}
	}
	return 0;
}