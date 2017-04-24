#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	string a;
	int flag[1000001];
	getline(cin, a);
	int cnt=0,one=0,zero=0,flag_add=0;
	
	if (a[0] == ' ' || a[0] == '\t' || a[0] == '\n' || a[0] == '\0') {
		flag[0] = 0;
	}
	else {
		flag[0] = 1;
	}
	flag_add++;
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == ' ' || a[i] == '\t' && flag[flag_add-1]==1 && flag_add-1>=0) {
			flag[flag_add++] = 0;
		}
		else if(flag[flag_add-1] == 0 && flag_add-1>=0){
			flag[flag_add++] = 1;
		}
	}

	for (int i = 0; i < flag_add; i++) {
		if (flag[i] == 1) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}