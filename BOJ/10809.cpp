#include <iostream>
using namespace std;

int main() {
	char a[101],add=0;
	//97~122 ¾ËÆÄºª
	//char alpa[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int result[26];
	cin >> a;

	for (int i = 0; i < 26; i++) {
		result[i] = -1;
	}
	
	while (1) {
		if (a[add] == ' ' || a[add] == NULL || a[add] == '\0') {
			break;
		}
		if ((int)a[add] >= 97 && (int)a[add] <= 122 && result[(int)a[add] - 97]== -1) {
			result[(int)a[add] - 97] = add;
		}
		add++;
	}

	for (int i = 0; i < 26; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}