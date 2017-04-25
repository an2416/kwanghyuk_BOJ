/*
           카운팅 정렬            
 중복된 수를 정렬할때 유용         
 숫자의 범위가 한정적일때 유용     
*/

#include <iostream>
using namespace std;

int main() {
	int n, num[10001];  // num안의 숫자는 최대 허용 숫자 범위
	for (int i = 0; i < 10001; i++) {  // 0으로 초기화 시켜주어야 나중에 카운팅할 수 있음.
		num[i] = 0;
	}
	ios::sync_with_stdio(false);  // 동기화 false  -> cin 속도 극대화
	cin >> n;

	for (int i = 0; i < n; i++) {    // 입력받는 수를 배열의 index로 입력받아 카운팅해준다.
		int a;
		cin >> a;
		num[a]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << '\n';   // endl -> '\n'으로 써야 편함.
		}
	}
	return 0;
}